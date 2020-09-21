#include "Layer.h"

Layer::Layer(Handler *handler) : handler(handler) {}

bool Layer::handle(Context *context) {
    bool matched = this->match(context);

    if (matched) {
        this->handler->handle(context);
    }

    return matched;
}

std::vector<CacheKey> *Layer::getCacheKeys() {
    return nullptr;
}
