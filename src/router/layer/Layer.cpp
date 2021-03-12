#include "Layer.h"

Layer::Layer(Handler *handler) : handler(handler) {}

Layer *Layer::handle(Context *context) {
    this->handler->handle(context);
    return this;
}

bool Layer::matchUrl(Context *context) {
    return this->match(context);
}

std::vector<CacheKey> *Layer::getCacheKeys() {
    return nullptr;
}
