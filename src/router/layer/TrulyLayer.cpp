#include "TrulyLayer.h"

TrulyLayer::TrulyLayer(Handler *handler) : Layer(handler) {}

bool TrulyLayer::match(Context *context) {
    return true;
}
