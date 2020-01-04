#include <sys/types.h>
#include <cstdio>
#include <fcgiapp.h>
#include <string>
#include <iostream>
#include <cstring>


#define THREAD_COUNT 2
#define SOCKET_PATH "127.0.0.1:8000"

using namespace std;

//хранит дескриптор открытого сокета
static int socketId;

static void *doit() {
    int rc, i;
    FCGX_Request request;
    char *server_name;

    if (FCGX_InitRequest(&request, socketId, 0) != 0) {
        //ошибка при инициализации структуры запроса
        printf("Can not init request\n");
        return NULL;
    }

    for (;;) {
        //попробовать получить новый запрос
        printf("Try to accept new request\n");
        rc = FCGX_Accept_r(&request);
        printf("%i ", rc);

        if (rc < 0) {
            //ошибка при получении запроса
            printf("Can not accept new request\n");
            break;
        }
        printf("request is accepted\n");

        // Вывод всех хедеров с дополнительными переменными FastCGI
        char **env = request.envp;
        while (*(++env))
            puts(*env);

        // Получаем вход запроса
        string input;
        int len;
        char *buf = new char[1024];
        while ((len = FCGX_GetStr(buf, 1024, request.in)) > 0) {
            for (int j = 0; j < len; ++j) input += buf[j];
        }

        cout << input << endl;

        //получить значение переменной
        server_name = FCGX_GetParam("SERVER_NAME", request.envp);
        //вывести все HTTP-заголовки (каждый заголовок с новой строки)
        FCGX_PutS("Status: 200 OK\r\n", request.out);
        FCGX_PutS("Content-Type: text/html\r\n", request.out);
//        FCGX_PutS("Location: https://yandex.ru/\r\n", request.out);
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

int main(void) {
    int i;
    pthread_t id[THREAD_COUNT];

    //инициализация библилиотеки
    FCGX_Init();
    printf("Lib is inited\n");

    //открываем новый сокет
    socketId = FCGX_OpenSocket(SOCKET_PATH, 20);
    if (socketId < 0) {
        //ошибка при открытии сокета
        return 1;
    }
    printf("Socket is opened\n");

    doit();
    return 0;
}