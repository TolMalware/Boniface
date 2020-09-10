#ifndef WEB_FRAMEWORK_MIDDLEWAREMANAGER_H
#define WEB_FRAMEWORK_MIDDLEWAREMANAGER_H


#include <list>
#include <functional>
#include <vector>
#include "../context/Context.h"


class Middleware {
public:
    std::function<void(Context *, Middleware)> handler;
    std::vector<std::string> methods = {"POST", "GET", "PUT", "DELETE"};
};

using MiddlewareFunc = std::function<void(Context *, Middleware)>;
using MiddlewareIterator = std::_List_iterator<Middleware>;

class MiddlewareManager {
public:
    static Middleware compose(std::list<Middleware> *middleware);

    MiddlewareManager();

    std::list<Middleware> *middlewares;
    Middleware composedMiddlewares;

    void handleRequest(Context *context);

    void composeMiddleware();
};


#endif //WEB_FRAMEWORK_MIDDLEWAREMANAGER_H
