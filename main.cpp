#include <pthread.h>
#include <sys/types.h>
#include <stdio.h>

#include "fcgi_config.h"
#include "fcgiapp.h"


#define THREAD_COUNT 2
#define SOCKET_PATH "127.0.0.1:8000"

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

        //попробовать получить новый запрос
        printf("Try to accept new request\n");
        printf("Try to accept new request11\n");
        rc = FCGX_Accept_r(&request);
        printf("%i",rc);
        printf("Try to accept new request222\n");
        printf("Try to accept new request333\n");

        if(rc < 0)
        {
            //ошибка при получении запроса
            printf("Can not accept new request\n");
            break;
        }
        printf("request is accepted\n");

        //получить значение переменной
        server_name = FCGX_GetParam("SERVER_NAME", request.envp);
        printf("%s", server_name);
        //вывести все HTTP-заголовки (каждый заголовок с новой строки)
        FCGX_PutS("Content-type: text/html\r\n", request.out);
        //между заголовками и телом ответа нужно вывести пустую строку
        FCGX_PutS("\r\n", request.out);
        //вывести тело ответа (например - html-код веб-страницы)
        FCGX_PutS("<html>\r\n", request.out);
        FCGX_PutS("<head>\r\n", request.out);
        FCGX_PutS("<title>FastCGI Hello! (multi-threaded C, fcgiapp library)</title>\r\n", request.out);
        FCGX_PutS("</head>\r\n", request.out);
        FCGX_PutS("<body>\r\n", request.out);
        FCGX_PutS("<h1>FastCGI Hello! (multi-threaded C, fcgiapp library)</h1>\r\n", request.out);
        FCGX_PutS("<p>Request accepted from host <i>", request.out);
        FCGX_PutS(server_name ? server_name : "?", request.out);
        FCGX_PutS("</i></p>\r\n", request.out);
        FCGX_PutS("</body>\r\n", request.out);
        FCGX_PutS("</html>\r\n", request.out);

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
    printf("Socket is opened\n");

    doit();
    return 0;
}