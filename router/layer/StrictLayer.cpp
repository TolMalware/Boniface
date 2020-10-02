#include <utility>
#include "StrictLayer.h"
#include <iostream>

StrictLayer::StrictLayer(std::string path, uint8_t methods, Handler *handler) :
    Layer(handler),
    path(std::move(path)),
    methods(methods) {}

bool StrictLayer::match(Context *context) {
    return this->matchUrl(context) && context->request->methodMask & this->methods;
}

bool StrictLayer::matchUrl(Context *context) {
    return context->request->path == this->path;
}
