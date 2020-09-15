#include <iostream>
#include <vector>
#include "Router.h"


void Router::addHandler(const std::string &url, const MiddlewareFunc &handler) {
    if (this->handlers_map->count(url) == 0) {
        this->handlers_map->insert(std::pair<std::string, std::list<MiddlewareFunc>>(url, {}));
    }
    this->handlers_map->at(url).push_back(handler);
}

std::list<MiddlewareFunc> *Router::getHandler(const std::string &url) {
    if (this->handlers_map->count(url) != 0) {
        return &this->handlers_map->at(url);
    }
    auto not_found = new std::list<MiddlewareFunc>;
    not_found->emplace_back([](Context* context, const NextFunc& next) {
        context->response->body ="404";
        context->response->set_status(404);
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
    handlers_map = new std::map<std::string, std::list<MiddlewareFunc>>;
}
