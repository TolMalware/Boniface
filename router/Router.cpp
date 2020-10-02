#include "Router.h"
#include "RouterMiddleware.h"
#include "layer/StrictLayer.h"
#include "handler/HandlerSetStatusCode.h"

Router::Router() : Router(new HandlerSetStatusCode(404), new HandlerSetStatusCode(405)) {}

Router::Router(Handler *defaultHandler) : Router(defaultHandler, new HandlerSetStatusCode(405)) {}

Router::Router(Handler *defaultHandler, Handler *defaultHandlerForMatchedUrl) {
    this->defaultHandler = defaultHandler;
    this->defaultHandlerForMatchedUrl = defaultHandlerForMatchedUrl;
    this->layers = std::list<Layer*>();
}

bool Router::handle(Context *context) {
    bool matchedUrl = false;

    for (auto const &layer : this->layers) {
        bool matched = layer->match(context);
        matchedUrl = matchedUrl || matched || layer->matchUrl(context);

        if (matched) {
            layer->handle(context);
            return true;
        }
    }

    if (matchedUrl && this->defaultHandlerForMatchedUrl != nullptr) {
        this->defaultHandlerForMatchedUrl->handle(context);
        return true;
    }

    if (this->defaultHandler != nullptr) {
        this->defaultHandler->handle(context);
        return true;
    }

    return false;
}

Middleware *Router::getMiddleware() {
    return new RouterMiddleware(this);
}

Router &Router::route(const std::string &path, uint8_t methods, Handler *handler) {
    auto layer = new StrictLayer(path, methods, handler);
    this->layers.push_back(layer);

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
