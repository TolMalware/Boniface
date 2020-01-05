#ifndef WEB_FRAMEWORK_ROUTER_H
#define WEB_FRAMEWORK_ROUTER_H

#include "../context/Context.h"
#include "../middleware/MiddlewareManager.h"
#include <functional>
#include <map>
class Router{
    std::map<std::string,std::list<MiddlewareFunc>>* handlersMap;

    std::list<MiddlewareFunc> *getHandler(const std::string& url);

public:
    void addHandler(const std::string& url,const MiddlewareFunc&);
    MiddlewareFunc getRoutingMiddleware();

    Router();
};
#endif //WEB_FRAMEWORK_ROUTER_H
