#include "App.h"
#include <string>

App::App(const char *address){
    FCGX_Init();

    socketId = FCGX_OpenSocket(address, 20);
    if(FCGX_InitRequest(&request, socketId, 0) != 0)
    {
        //ошибка при инициализации структуры запроса
        printf("Can not init request\n");}
    }

void App::start(){
    while (true){
        auto rc = FCGX_Accept_r(&request);

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

int main(){
    auto app = App("127.0.0.1:8000");
    app.start();

}