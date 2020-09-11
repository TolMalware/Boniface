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

    std::list<MiddlewareFunc> *getHandler(url_with_methods key);

public:
    MiddlewareFunc getRoutingMiddleware();

    Router();

    void addHandler(const std::string &url, const MiddlewareFunc &handler,
                    std::vector<std::string> methods = {"GET", "POST", "PUT", "DELETE"});
};

#endif //WEB_FRAMEWORK_ROUTER_H
