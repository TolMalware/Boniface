#ifndef WEB_FRAMEWORK_ROUTER_H
#define WEB_FRAMEWORK_ROUTER_H

#include "../context/Context.h"
#include "../middleware/MiddlewareManager.h"
#include <functional>
#include <map>
#include <vector>

class Router {
    std::map<std::string, std::list<MiddlewareFunc>> *handlersMap;

    std::list<MiddlewareFunc> *getHandler(const std::string &url);

public:
    MiddlewareFunc getRoutingMiddleware();

    Router();

    void addHandler(const std::string &url, const MiddlewareFunc &handler,
                    const std::vector<std::string> &methods = {"POST", "GET", "PUT", "GET"});
};

#endif //WEB_FRAMEWORK_ROUTER_H
