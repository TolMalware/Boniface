#ifndef WEB_FRAMEWORK_ROUTER_H
#define WEB_FRAMEWORK_ROUTER_H


#include <map>
#include <list>
#include "../middleware/LambdaMiddleware.h"
#include "Layer.h"

class Router {
private:
    std::list<Layer*> layers;
    std::map<CacheKey, Layer*> cache;

public:
    Router();

    Layer *handle(Context *context);
    Middleware *getMiddleware();

    Router &use(const std::string &path, uint8_t methods, Middleware *middleware);
    Router &use(const std::string &path, uint8_t methods, MiddlewareFunc middleware);

    Router &GET(const std::string &path, Middleware *middleware);
    Router &GET(const std::string &path, MiddlewareFunc middleware);
    Router &POST(const std::string &path, Middleware *middleware);
    Router &POST(const std::string &path, MiddlewareFunc middleware);
    Router &PUT(const std::string &path, Middleware *middleware);
    Router &PUT(const std::string &path, MiddlewareFunc middleware);
    Router &DELETE(const std::string &path, Middleware *middleware);
    Router &DELETE(const std::string &path, MiddlewareFunc middleware);

    void cacheLayer(Layer *layer);
};


#endif //WEB_FRAMEWORK_ROUTER_H
