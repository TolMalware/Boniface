#ifndef WEB_FRAMEWORK_MIDDLEWAREMANAGER_H
#define WEB_FRAMEWORK_MIDDLEWAREMANAGER_H


#include <list>
#include <functional>
#include "../context/Context.h"

using NextFunc = std::function<void(void)>;
using MiddlewareFunc = std::function<void(Context*, NextFunc)>;
using MiddlewareIterator = std::_List_iterator<MiddlewareFunc>;

class MiddlewareManager {
public:
    static MiddlewareFunc compose(std::list<MiddlewareFunc> *middleware);

    MiddlewareManager();
    std::list<MiddlewareFunc>* middleware;
    MiddlewareFunc composedMiddleware;

    void handleRequest(Context* context);
    void composeMiddleware();
};


#endif //WEB_FRAMEWORK_MIDDLEWAREMANAGER_H
