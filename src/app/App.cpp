#include "App.h"
#include <vector>
#include <cstring>

App::App() {
    this->middlewareManager = MiddlewareManager();
    FCGX_Init();
}

App &App::use(Middleware *middleware) {
    this->middlewareManager.use(middleware);
    return *this;
}


void App::start(const std::string& host, const int port) {
    const auto address = host + ":"+ std::to_string(port);
    int socketId = FCGX_OpenSocket(address.c_str(),20);
    FCGX_Request request;

    if (FCGX_InitRequest(&request, socketId, 0) != 0) {
        printf("Can not init request\n");
        exit(1);
    }

    while (true) {
        auto rc = FCGX_Accept_r(&request);
        if (rc < 0) {
            exit(10);
        }

        auto context = new Context(&request);
        middlewareManager.handle(context);

        auto str_header = context->response->headers_to_string();
        FCGX_PutS(str_header.c_str(), request.out);
        FCGX_PutS("Content-type: application/json\r\n\r\n", request.out);
        for (size_t i = 0; i < strlen(context->response->body); i++) {
            FCGX_PutChar(context->response->body[i], request.out);
        }
        FCGX_Finish_r(&request);
    }
}
