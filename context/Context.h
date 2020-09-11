#ifndef WEB_FRAMEWORK_CONTEXT_H
#define WEB_FRAMEWORK_CONTEXT_H


#include "request/Request.h"
#include "response/Response.h"

class Context {
public:
    Request *request;
    Response *response;
    std::map<std::string, void*> *state;

    Context(FCGX_Request* fcgxRequest);

    void write(const std::string& body);
};


#endif //WEB_FRAMEWORK_CONTEXT_H
