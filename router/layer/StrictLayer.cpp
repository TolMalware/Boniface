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

std::vector<CacheKey> *StrictLayer::getCacheKeys() {
    auto keys = new std::vector<CacheKey>();

    // TODO: refactor this
    if (this->methods & GET_METHOD) keys->emplace_back(this->path, GET_METHOD);
    if (this->methods & POST_METHOD) keys->emplace_back(this->path, POST_METHOD);
    if (this->methods & PUT_METHOD) keys->emplace_back(this->path, PUT_METHOD);
    if (this->methods & DELETE_METHOD) keys->emplace_back(this->path, DELETE_METHOD);

    return keys;
}
