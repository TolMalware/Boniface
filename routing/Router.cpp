#include <iostream>
#include <vector>
#include "Router.h"


void Router::addHandler(const std::string &url, const MiddlewareFunc &handler,
                        std::vector<std::string> methods) {
    if (this->handlers_map->count({url, methods}) == 0) {
        this->handlers_map->insert({{url, methods}, {}});
    }
    this->handlers_map->at(std::make_pair(url, methods)).push_back(handler);
}

std::list<MiddlewareFunc> *Router::getHandler(url_with_methods key) {
    if (this->handlers_map->count({key.first, key.second}) != 0) {
        return &this->handlers_map->at({key.first, key.second});
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
        auto handler = this->getHandler({context->request->url, {context->request->method}});
        MiddlewareManager::compose(handler)(context, next);
    };
}

Router::Router() {
    handlers_map = new std::map<url_with_methods, std::list<MiddlewareFunc>>;
}
