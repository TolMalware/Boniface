#ifndef WEB_FRAMEWORK_CONTEXT_H
#define WEB_FRAMEWORK_CONTEXT_H


#include "request/Request.h"
#include "response/Response.h"

class Context {
public:
    Context();

    Request *request;
    Response *response;
    std::map<std::string, void*> *state;

    explicit Context(FCGX_Request* fcgxRequest);
    void write(const std::string& data) const;
};


#endif //WEB_FRAMEWORK_CONTEXT_H
