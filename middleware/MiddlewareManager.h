#ifndef WEB_FRAMEWORK_MIDDLEWAREMANAGER_H
#define WEB_FRAMEWORK_MIDDLEWAREMANAGER_H


#include <list>
#include <functional>
#include "../context/Context.h"

using NextFunc = std::function<void(void)>;
using MiddlewareFunc = std::function<void(Context*)>;
using MiddlewareIterator = std::_List_iterator<MiddlewareFunc>;

class Middleware{
public:
    Middleware();

    Middleware* nextMiddleware{};
    std::string methods;
    MiddlewareFunc handler;
    explicit Middleware(MiddlewareFunc handler);
    void handle_request(Context* context);
};

class MiddlewareManager {
public:

    MiddlewareManager();

    static Middleware compose(std::list<Middleware> *middleware);
    std::list<Middleware>* middlewares = new std::list<Middleware>;
    Middleware composedMiddleware;

    void handleRequest(Context* context);
    void composeMiddleware();
};


#endif //WEB_FRAMEWORK_MIDDLEWAREMANAGER_H
