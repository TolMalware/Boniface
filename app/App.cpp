#include "App.h"
#include <string>
#include "../context/Context.h"

App::App(){
    FCGX_Init();
    if(FCGX_InitRequest(&request, socketId, 0) != 0)
    {
        //ошибка при инициализации структуры запроса
        printf("Can not init request\n");}
    }

void App::start(const char *address){
    socketId = FCGX_OpenSocket(address, 20);
    while (true){
        auto rc = FCGX_Accept_r(&request);
        auto context = new Context(&request);
        middlewareManager->composeMiddleware();
        middlewareManager->handleRequest(context);

        if(rc < 0)
        {
            //ошибка при получении запроса
            exit(10);
        }
        FCGX_PutS("Content-type: text/html\r\n\r\n", request.out);
        FCGX_PutS("dedeaddezzd\r\n\r\n", request.out);


        //закрыть текущее соединение
        FCGX_Finish_r(&request);
    }

}