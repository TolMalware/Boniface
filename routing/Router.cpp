#include <iostream>
#include <vector>
#include "Router.h"

void Router::addHandler(const std::string &url,
                        const MiddlewareFunc &handler,
                        const std::vector<std::string>& methods = {"GET", "POST", "PUT", "DELETE"}) {
    auto middleware = new Middleware(handler, methods);
    if (this->handlers_map->count(url) == 0) {
        this->handlers_map->insert({url , new std::list<Middleware *>()});
    }
    this->handlers_map->at(url)->push_back(middleware);
}

std::list<Middleware *> *Router::getHandler(const std::string &url) {
    return this->handlers_map->at(url);
}

Middleware *Router::getRoutingMiddleware() {
    return new Middleware([this](Context *context) {
      if (this->handlers_map->count(context->request->url) == 0) {
          NotFoundMiddleware::handler(context);

      } else {
          auto handler = this->getHandler(context->request->url);
          MiddlewareManager::compose(handler)->handle_request(context);
      }
    });
}

Router::Router() {
    handlers_map = new std::map<std::string, std::list<Middleware *> *>;
}
