#ifndef WEB_FRAMEWORK_MIDDLEWAREMANAGER_H
#define WEB_FRAMEWORK_MIDDLEWAREMANAGER_H

#include "../context/Context.h"
#include "Middleware.h"

class MiddlewareManager {
private:
    Middleware *head = nullptr;
    Middleware *tail = nullptr;

public:
    void use(Middleware *middleware);
    void handle(Context *context);
};

#endif //WEB_FRAMEWORK_MIDDLEWAREMANAGER_H
