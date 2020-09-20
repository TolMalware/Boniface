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

    void cacheLayer(Layer *layer);
};


#endif //WEB_FRAMEWORK_ROUTER_H
