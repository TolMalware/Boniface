#ifndef WEB_FRAMEWORK_ROUTER_H
#define WEB_FRAMEWORK_ROUTER_H

#include "../context/Context.h"
#include "../middleware/MiddlewareManager.h"
#include <functional>
#include <map>
#include <vector>

class Router {
    std::map<std::string, std::list<MiddlewareFunc>> *handlers_map;
    std::map<std::string, std::vector<std::string>> *allowed_methods_map;

    std::list<MiddlewareFunc> *getHandler(const std::string& key, const std::string &method);

public:
    MiddlewareFunc getRoutingMiddleware();

    Router();

    void addHandler(const std::string &url, const MiddlewareFunc &handler,
                    const std::vector<std::string>& methods = {"GET", "POST", "PUT", "DELETE"});
};

#endif //WEB_FRAMEWORK_ROUTER_H
