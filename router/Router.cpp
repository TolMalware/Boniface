#include "Router.h"
#include "RouterMiddleware.h"
#include "layer/StrictLayer.h"

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

Router &Router::use(const std::string &path, uint8_t methods, Handler *handler) {
    auto layer = new StrictLayer(path, methods, handler);
    this->layers.push_back(layer);
    this->cacheLayer(layer);

    return *this;
}

Router &Router::use(const std::string &path, uint8_t methods, HandlerFunc handler) {
    return this->use(path, methods, new LambdaHandler(handler));
}

Router &Router::GET(const std::string &path, Handler *handler) {
    return this->use(path, GET_METHOD, handler);
}

Router &Router::GET(const std::string &path, HandlerFunc handler) {
    return this->use(path, GET_METHOD, new LambdaHandler(handler));
}

Router &Router::POST(const std::string &path, Handler *handler) {
    return this->use(path, POST_METHOD, handler);
}

Router &Router::POST(const std::string &path, HandlerFunc handler) {
    return this->use(path, POST_METHOD, new LambdaHandler(handler));
}

Router &Router::PUT(const std::string &path, Handler *handler) {
    return this->use(path, PUT_METHOD, handler);
}

Router &Router::PUT(const std::string &path, HandlerFunc handler) {
    return this->use(path, PUT_METHOD, new LambdaHandler(handler));
}

Router &Router::DELETE(const std::string &path, Handler *handler) {
    return this->use(path, DELETE_METHOD, handler);
}

Router &Router::DELETE(const std::string &path, HandlerFunc handler) {
    return this->use(path, DELETE_METHOD, new LambdaHandler(handler));
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
