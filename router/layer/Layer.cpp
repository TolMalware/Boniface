#include "Layer.h"

Layer::Layer(Handler *handler) : handler(handler) {}

void Layer::handle(Context *context) {
    this->handler->handle(context);
}

bool Layer::matchUrl(Context *context) {
    return this->match(context);
}
