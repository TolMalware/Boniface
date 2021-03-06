#ifndef WEB_FRAMEWORK_ROUTER_H
#define WEB_FRAMEWORK_ROUTER_H


#include <map>
#include <list>
#include "../middleware/Middleware.h"
#include "layer/Layer.h"
#include "LambdaHandler.h"

class Router {
private:
    Layer *defaultLayer;
    Layer *defaultLayerForMatchedUrl;
    std::list<Layer*> layers;
    std::map<CacheKey, Layer*> cache;

public:
    Router();
    explicit Router(Layer *defaultLayer);
    explicit Router(Layer *defaultLayer, Layer *defaultLayerForMatchedUrl);

    Layer *handle(Context *context);
    Middleware *getMiddleware();

    Router &route(const std::string &path, uint8_t methods, Handler *handler);
    Router &route(const std::string &path, uint8_t methods, HandlerFunc handler);

    Router &GET(const std::string &path, Handler *handler);
    Router &GET(const std::string &path, HandlerFunc handler);
    Router &POST(const std::string &path, Handler *handler);
    Router &POST(const std::string &path, HandlerFunc handler);
    Router &PUT(const std::string &path, Handler *handler);
    Router &PUT(const std::string &path, HandlerFunc handler);
    Router &DELETE(const std::string &path, Handler *handler);
    Router &DELETE(const std::string &path, HandlerFunc handler);

    void cacheLayer(Layer *layer);
};


#endif //WEB_FRAMEWORK_ROUTER_H
