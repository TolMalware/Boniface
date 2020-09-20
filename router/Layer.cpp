#include "Layer.h"

Layer::Layer(Middleware *middleware) : middleware(middleware) {}

bool Layer::handle(Context *context) {
    bool matched = this->match(context);

    if (matched) {
        this->middleware->handle(context);
    }

    return matched;
}

std::vector<CacheKey> *Layer::getCacheKeys() {
    return nullptr;
}
