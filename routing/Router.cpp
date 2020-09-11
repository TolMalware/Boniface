#include <iostream>
#include <vector>
#include <algorithm>
#include "Router.h"


void Router::addHandler(const std::string &url, const MiddlewareFunc &handler,
                        const std::vector<std::string> &methods) {
    if (this->handlers_map->count(url) == 0) {
        this->handlers_map->insert({url, {}});
    }
    this->allowed_methods_map->insert({url, methods});
    this->handlers_map->at(url).push_back(handler);
}

std::list<MiddlewareFunc> *Router::getHandler(const std::string &key, const std::string &method) {
    if (this->handlers_map->count(key) != 0) {
        auto methods = this->allowed_methods_map->at(key);
        if (std::find(methods.begin(), methods.end(), method)!=methods.end()) {
            return &this->handlers_map->at(key);
        }
    }
    auto not_found = new std::list<MiddlewareFunc>;
    not_found->emplace_back([](Context *context, const NextFunc &next) {
        context->response->body = "404";
        context->response->set_status(404);
        next();
    });
    return not_found;
}

MiddlewareFunc Router::getRoutingMiddleware() {
    return [this](Context *context, const NextFunc &next) {
        auto handler = this->getHandler(context->request->url, context->request->method);
        MiddlewareManager::compose(handler)(context, next);
    };
}

Router::Router() {
    handlers_map = new std::map<std::string, std::list<MiddlewareFunc>>;
}
