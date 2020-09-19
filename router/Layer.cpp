#include "Layer.h"

Layer::Layer(const std::string &path, uint8_t methods, Middleware *middleware) {
    this->path = path;
    this->methods = methods;
    this->middleware = middleware;
}

bool Layer::match(Context *context) {
    // TODO: Add regexp and url params
    return context->request->path == this->path && context->request->methodMask & this->methods;
}

bool Layer::handle(Context *context) {
    bool matched = this->match(context);

    if (matched) {
        this->middleware->handle(context);
    }

    return matched;
}
