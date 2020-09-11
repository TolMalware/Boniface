#ifndef WEB_FRAMEWORK_ROUTER_H
#define WEB_FRAMEWORK_ROUTER_H

#include "../context/Context.h"
#include "../middleware/MiddlewareManager.h"
#include <functional>
#include <map>
#include <vector>


using url_with_methods = std::pair<std::string, std::vector<std::string>>;

class Router {
    std::map<url_with_methods, std::list<MiddlewareFunc>> *handlers_map;
    std::map<MiddlewareFunc, std::vector<std::string>> *allowed_methods_map;

    std::list<MiddlewareFunc> *getHandler(const std::string &url);

public:
    MiddlewareFunc getRoutingMiddleware();

    Router();

    void addHandler(const std::string &url, const MiddlewareFunc &handler,
                    const std::vector<std::string> methods = {"GET", "POST", "PUT", "DELETE"});
};

#endif //WEB_FRAMEWORK_ROUTER_H
