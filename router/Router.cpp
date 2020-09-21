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
    return this->use(path, methods, new LambdaMiddleware(middleware));
}

Router &Router::GET(const std::string &path, Middleware *middleware) {
    return this->use(path, GET_METHOD, middleware);
}

Router &Router::GET(const std::string &path, MiddlewareFunc middleware) {
    return this->use(path, GET_METHOD, new LambdaMiddleware(middleware));
}

Router &Router::POST(const std::string &path, Middleware *middleware) {
    return this->use(path, POST_METHOD, middleware);
}

Router &Router::POST(const std::string &path, MiddlewareFunc middleware) {
    return this->use(path, POST_METHOD, new LambdaMiddleware(middleware));
}

Router &Router::PUT(const std::string &path, Middleware *middleware) {
    return this->use(path, PUT_METHOD, middleware);
}

Router &Router::PUT(const std::string &path, MiddlewareFunc middleware) {
    return this->use(path, PUT_METHOD, new LambdaMiddleware(middleware));
}

Router &Router::DELETE(const std::string &path, Middleware *middleware) {
    return this->use(path, DELETE_METHOD, middleware);
}

Router &Router::DELETE(const std::string &path, MiddlewareFunc middleware) {
    return this->use(path, DELETE_METHOD, new LambdaMiddleware(middleware));
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
