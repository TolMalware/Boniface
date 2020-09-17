#include <iostream>
#include <vector>
#include "Router.h"


void Router::addHandler(const std::string &url, const MiddlewareFunc &handler) {
    auto middleware=Middleware(handler);

    if (this->handlers_map->count(url) == 0) {
        this->handlers_map->insert(std::pair<std::string, std::list<Middleware>>(url, {}));
    }
    this->handlers_map->at(url).push_back(middleware);
}

std::list<Middleware> *Router::getHandler(const std::string &url) {
    if (this->handlers_map->count(url) != 0) {
        return &this->handlers_map->at(url);
    }
    auto not_found = new std::list<Middleware>;
    not_found->emplace_back([](Context *context) {
        context->response->body = "404";
        context->response->set_status(404);
    });
    return not_found;
}

Middleware Router::getRoutingMiddleware() {
    return Middleware([this](Context *context) {
        auto handler = this->getHandler(context->request->url);
        MiddlewareManager::compose(handler).handle_request(context);
    });
}

Router::Router() {
    handlers_map = new std::map<std::string, std::list<Middleware>>;
}
