#ifndef WEB_FRAMEWORK_REQUEST_H
#define WEB_FRAMEWORK_REQUEST_H


#include <string>
#include <map>
#include <fcgiapp.h>

class Request {
public:
    // TODO: распарсить и закинуть в переменную все переменные окружения
    int socketId = 0; // TODO: Разобраться, зачем вообще это нужно и что это

    std::map<std::string, std::string> *headers;
    std::string method;

    std::string protocol;
    std::string hostname;
    std::string port;
    std::string path;
    std::string querystring;
    char* body;
    std::string host;
    std::string origin;
    std::string search;
    std::string url;
    std::string href;


    size_t length;
    std::string type;

    std::map<std::string, std::string> *query;

    // TODO: params and body

    explicit Request(FCGX_Request *request);

    std::string get(const std::string& field) const;
};


#endif //WEB_FRAMEWORK_REQUEST_H
