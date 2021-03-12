#include "Router.h"
#include "RouterMiddleware.h"
#include "layer/TrulyLayer.h"
#include "layer/StrictLayer.h"
#include "handler/HandlerSetStatusCode.h"

Router::Router() : Router(
    new TrulyLayer(new HandlerSetStatusCode(404)), new TrulyLayer(new HandlerSetStatusCode(405))) {}

Router::Router(Layer *defaultLayer) : Router(defaultLayer, new TrulyLayer(new HandlerSetStatusCode(405))) {}

Router::Router(Layer *defaultLayer, Layer *defaultLayerForMatchedUrl) {
    this->defaultLayer = defaultLayer;
    this->defaultLayerForMatchedUrl = defaultLayerForMatchedUrl;
    this->layers = std::list<Layer*>();
    this->cache = std::map<CacheKey, Layer*>();
}

Layer *Router::handle(Context *context) {
    auto key = CacheKey(context->request->path, context->request->methodMask);
    auto cachedLayer = this->cache.find(key);

    if (cachedLayer != this->cache.end()) {
        return (*cachedLayer).second->handle(context);
    }

    bool matchedUrl = false;

    for (auto const &layer : this->layers) {
        bool matched = layer->match(context);
        matchedUrl = matchedUrl || matched || layer->matchUrl(context);

        if (matched) {
            this->cacheLayer(layer);
            return layer->handle(context);
        }
    }

    if (matchedUrl) {
        return this->defaultLayerForMatchedUrl->handle(context);
    }

    return this->defaultLayer->handle(context);
}

Middleware *Router::getMiddleware() {
    return new RouterMiddleware(this);
}

Router &Router::route(const std::string &path, uint8_t methods, Handler *handler) {
    auto layer = new StrictLayer(path, methods, handler);
    this->layers.push_back(layer);
    this->cacheLayer(layer);

    return *this;
}

Router &Router::route(const std::string &path, uint8_t methods, HandlerFunc handler) {
    return this->route(path, methods, new LambdaHandler(handler));
}

Router &Router::GET(const std::string &path, Handler *handler) {
    return this->route(path, GET_METHOD, handler);
}

Router &Router::GET(const std::string &path, HandlerFunc handler) {
    return this->route(path, GET_METHOD, new LambdaHandler(handler));
}

Router &Router::POST(const std::string &path, Handler *handler) {
    return this->route(path, POST_METHOD, handler);
}

Router &Router::POST(const std::string &path, HandlerFunc handler) {
    return this->route(path, POST_METHOD, new LambdaHandler(handler));
}

Router &Router::PUT(const std::string &path, Handler *handler) {
    return this->route(path, PUT_METHOD, handler);
}

Router &Router::PUT(const std::string &path, HandlerFunc handler) {
    return this->route(path, PUT_METHOD, new LambdaHandler(handler));
}

Router &Router::DELETE(const std::string &path, Handler *handler) {
    return this->route(path, DELETE_METHOD, handler);
}

Router &Router::DELETE(const std::string &path, HandlerFunc handler) {
    return this->route(path, DELETE_METHOD, new LambdaHandler(handler));
}

void Router::cacheLayer(Layer *layer) {
    auto keys = layer->getCacheKeys();
    if (keys == nullptr) return;

    for (auto const &key : *keys)  {
        if (this->cache.find(key) != this->cache.end()) {
            this->cache.insert(std::make_pair(key, layer));
        }
    }
}
