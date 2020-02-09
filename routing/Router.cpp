#include <iostream>
#include "Router.h"


void Router::addHandler(const std::string &url, const MiddlewareFunc &handler) {
    if (!this->handlersMap->contains(url)) {
        this->handlersMap->insert(std::pair<std::string, std::list<MiddlewareFunc>>(url, std::list<MiddlewareFunc>()));
    }
    this->handlersMap->at(url).push_back(handler);
}

std::list<MiddlewareFunc> *Router::getHandler(const std::string &url) {
    if (this->handlersMap->contains(url)) {
        return &this->handlersMap->at(url);
    }
    auto not_found = new std::list<MiddlewareFunc>;
    not_found->emplace_back([](Context* context, const NextFunc& next) {
        context->response->body = const_cast<char *>("404 aaaaaaaaa");
        next();
    });
    return not_found;
}

MiddlewareFunc Router::getRoutingMiddleware() {
    return [this](Context *context, const NextFunc &next) {
        auto handler = this->getHandler(context->request->url);
        MiddlewareManager::compose(handler)(context, next);
};}

Router::Router() {
    handlersMap = new std::map<std::string, std::list<MiddlewareFunc>>;
}
