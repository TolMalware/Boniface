#ifndef WEB_FRAMEWORK_REQUEST_H
#define WEB_FRAMEWORK_REQUEST_H

#include <string>
#include <map>
#include <fcgiapp.h>

class Request {
public:
    FCGX_Request *request;

    std::map<std::string, std::string> *headers;
    std::string method;

    std::string protocol;
    std::string hostname;
    std::string port;
    std::string path;
    std::string search;

    std::string host;
    std::string origin;
    std::string querystring;
    std::string url;
    std::string href;

    uint length;
    std::string type;
    std::string charset;

    std::map<std::string, std::string> *query;

    std::string get(std::string field);
};

#endif //WEB_FRAMEWORK_REQUEST_H
