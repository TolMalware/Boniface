#include "Router.h"
#include "RouterMiddleware.h"

Router::Router() {
    this->layers = std::list<Layer*>();
}

Layer *Router::handle(Context *context) {
    for (auto const &layer : this->layers) {
        bool handled = layer->handle(context);
        if (handled) return layer;
    }

    return nullptr;
}

Middleware *Router::getMiddleware() {
    return new RouterMiddleware(this);
}

Router &Router::use(const std::string &path, uint8_t methods, Middleware *middleware) {
    auto layer = new Layer(path, methods, middleware);
    this->layers.push_back(layer);

    return *this;
}

Router &Router::use(const std::string &path, uint8_t methods, MiddlewareFunc middleware) {
    this->use(path, methods, new LambdaMiddleware(middleware));

    return *this;
}
