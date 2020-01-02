#ifndef WEB_FRAMEWORK_CONTEXT_H
#define WEB_FRAMEWORK_CONTEXT_H


#include "Request.h"
#include "Response.h"

class Context {
public:
    Request *request;
    Response *response;
    std::map<std::string, void*> *state;
};


#endif //WEB_FRAMEWORK_CONTEXT_H
