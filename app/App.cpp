#include "App.h"
#include <future>
#include <iostream>
#include <vector>

std::mutex mtx;
App::App() {
    this->middlewareManager = MiddlewareManager();
    FCGX_Init();
}



auto a = Middleware([](Context *context) {
  std::cout<<"111111111";
  context->write(std::string("hi")); });

void App::run(){
    FCGX_Request request;
    if(FCGX_InitRequest(&request, socketId, 0) != 0)
    {
        printf("Can not init request\n");
    }
//    auto a = new Context();
//    middlewareManager.composedMiddleware.handler(a);
    while (true){
        auto rc = FCGX_Accept_r(&request);
        auto context = new Context(&request);
        middlewareManager.handleRequest(context);


        if(rc < 0){
            //ошибка при получении запроса
            exit(10);
        }
        auto str_header = context->response->headers_to_string();
        FCGX_PutS(str_header.c_str(), request.out);
        FCGX_PutS("Content-type: application/json\r\n\r\n", request.out);
        FCGX_PutS(context->response->body.c_str(), request.out);
        FCGX_Finish_r(&request);
    }

}

void App::start(const char *address){
    socketId = FCGX_OpenSocket(address, 20);
    std::cout<< this->middlewareManager.composedMiddleware.methods;
  this->middlewareManager.middlewares->emplace_front(a);
    middlewareManager.composeMiddleware();
    std::vector<std::thread> clients;
//    for (int i=0; i<2; i++){
//        std::thread T(&App::run, this);
//        clients.push_back(std::move(T));
//    }
//    for (auto &t:clients) {
//        t.join();
//    }
    this->run();
}