#include <sys/types.h>
#include <stdio.h>
#include <fcgiapp.h>
#include <string>
#include <iostream>


#define THREAD_COUNT 2
#define SOCKET_PATH "127.0.0.1:8000"

using namespace std;

//хранит дескриптор открытого сокета
static int socketId;

static void *doit()
{
    int rc, i;
    FCGX_Request request;
    char *server_name;

    if(FCGX_InitRequest(&request, socketId, 0) != 0)
    {
        //ошибка при инициализации структуры запроса
        printf("Can not init request\n");
        return NULL;
    }

    for(;;)
    {
        rc = FCGX_Accept_r(&request);

        if(rc < 0)
        {
            //ошибка при получении запроса
            printf("Can not accept new request\n");
            break;
        }
        //вывести все HTTP-заголовки (каждый заголовок с новой строки)
        FCGX_PutS("Content-type: text/html\r\n", request.out);
        //между заголовками и телом ответа нужно вывести пустую строку
        //FCGX_PutS("\r\n", request.out);
        //вывести тело ответа (например - html-код веб-страницы)
        //FCGX_PutS("ffxdzas\r\n", request.out);

        //"заснуть" - имитация многопоточной среды

        //закрыть текущее соединение
        FCGX_Finish_r(&request);

        //завершающие действия - запись статистики, логгирование ошибок и т.п.
    }

    return NULL;
}

int main(void)
{
    int i;
    pthread_t id[THREAD_COUNT];

    //инициализация библилиотеки
    FCGX_Init();
    printf("Lib is inited\n");

    //открываем новый сокет
    socketId = FCGX_OpenSocket(SOCKET_PATH, 20);
    if(socketId < 0)
    {
        //ошибка при открытии сокета
        return 1;
    }

    doit();
    return 0;
}