#ifndef WEB_FRAMEWORK_ROUTER_H
#define WEB_FRAMEWORK_ROUTER_H

#include "../context/Context.h"
#include "../middleware/MiddlewareManager.h"
#include <functional>
#include <map>
#include <vector>


class Router {
    std::map<std::string, std::list<MiddlewareFunc>> *handlers_map;
    std::map<MiddlewareFunc, std::vector<std::string>> *allowed_methods_map;
    std::list<MiddlewareFunc> *getHandler(const std::string &url);

public:
    MiddlewareFunc getRoutingMiddleware();

    Router();

    void addHandler(const std::string &url, const MiddlewareFunc &handler);
};

#endif //WEB_FRAMEWORK_ROUTER_H
