#ifndef WEB_FRAMEWORK_MIDDLEWAREMANAGER_H
#define WEB_FRAMEWORK_MIDDLEWAREMANAGER_H

#include <list>
#include <functional>
#include <vector>
#include "../context/Context.h"

using MiddlewareFunc = std::function<void(Context *)>;

class Middleware {
public:
    Middleware();

    Middleware(const MiddlewareFunc &function, const std::vector<std::string> &vector);

    Middleware *nextMiddleware{};
    std::vector<std::string> methods = {"GET", "POST", "PUT", "DELETE"};
    MiddlewareFunc handler;

    explicit Middleware(MiddlewareFunc handler);

    void handle_request(Context *context);
};

class MiddlewareManager {
public:

    MiddlewareManager();

    static Middleware *compose(std::list<Middleware *> *middleware);

    std::list<Middleware *> *middlewares = new std::list<Middleware *>;
    Middleware *composedMiddleware;

    void handleRequest(Context *context);

    void composeMiddleware();
};

class NotFoundMiddleware : public Middleware { ;
public:
    static const void handler(Context *context) {
        context->response->body = "404";
        context->response->set_status(404);
    }
};

class MethodNotAllowedMiddleware : public Middleware {
public:
    static const void handler(Context *context) {
        context->response->body = "405";
        context->response->set_status(405);
    };
};

#endif //WEB_FRAMEWORK_MIDDLEWAREMANAGER_H
