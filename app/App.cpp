#include "App.h"
#include <string>
#include <iostream>
#include "../context/Context.h"

App::App() {
    FCGX_Init();
    middlewareManager = new MiddlewareManager();
}

void App::start(const char *address){
    socketId = FCGX_OpenSocket(address, 20);
    middlewareManager->composeMiddleware();
    if(FCGX_InitRequest(&request, socketId, 0) != 0)
    {
        //ошибка при инициализации структуры запроса
        printf("Can not init request\n");}

    while (true){
        auto rc = FCGX_Accept_r(&request);
        auto context = new Context(&request);
        middlewareManager->handleRequest(context);

        if(rc < 0)
        {
            std::cout<<rc;
            //ошибка при получении запроса
            exit(10);
        }
        FCGX_PutS("Content-type: text/html\r\n\r\n", request.out);
        FCGX_PutS(context->response->body, request.out);
        FCGX_PutS("\r\n\r\n", request.out);


        //закрыть текущее соединение
        FCGX_Finish_r(&request);
    }

}

//int main(){
//    auto app = App("127.0.0.1:8000");
//    app.start();
//
//}