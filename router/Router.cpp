#include "Router.h"
#include "RouterMiddleware.h"
#include "StrictLayer.h"

Router::Router() {
    this->layers = std::list<Layer*>();
    this->cache = std::map<CacheKey, Layer*>();
}

Layer *Router::handle(Context *context) {
    auto key = CacheKey(context->request->path, context->request->methodMask);
    auto cachedLayer = this->cache.find(key);

    if (cachedLayer != this->cache.end()) {
        auto layer = (*cachedLayer).second;
        layer->handle(context);
        return layer;
    }

    for (auto const &layer : this->layers) {
        bool handled = layer->handle(context);

        if (handled) {
            this->cacheLayer(layer);
            return layer;
        }
    }

    return nullptr;
}

Middleware *Router::getMiddleware() {
    return new RouterMiddleware(this);
}

Router &Router::use(const std::string &path, uint8_t methods, Middleware *middleware) {
    auto layer = new StrictLayer(path, methods, middleware);
    this->layers.push_back(layer);
    this->cacheLayer(layer);

    return *this;
}

Router &Router::use(const std::string &path, uint8_t methods, MiddlewareFunc middleware) {
    this->use(path, methods, new LambdaMiddleware(middleware));

    return *this;
}

void Router::cacheLayer(Layer *layer) {
    auto keys = layer->getCacheKeys();
    if (keys == nullptr) return;

    for (auto const &key : *keys)  {
        this->cache.insert(std::make_pair(key, layer));
    }
}
