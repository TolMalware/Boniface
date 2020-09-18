#ifndef WEB_FRAMEWORK_ROUTER_H
#define WEB_FRAMEWORK_ROUTER_H

#include "../context/Context.h"
#include "../middleware/MiddlewareManager.h"
#include <functional>
#include <map>
#include <vector>


class Router {
    std::map<std::string, std::list<Middleware*>*> *handlers_map;
    std::list<Middleware *> * getHandler(const std::string &url);

public:
    Middleware getRoutingMiddleware();

    Router();

//    void addHandler(const std::string &url, const Middleware &handler);
    void addHandler(const std::string &url, const MiddlewareFunc& handler);
};

#endif //WEB_FRAMEWORK_ROUTER_H
