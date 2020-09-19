#include <iostream>
#include <utility>
#include <algorithm>
#include "MiddlewareManager.h"

Middleware *MiddlewareManager::compose(std::list<Middleware *> *middlewares) {
    auto it = middlewares->begin();
    if (middlewares->size() == 1) {
        return *middlewares->begin();
    }
    while (it != middlewares->end()) {
        Middleware *current = *it;
        it++;
        if (it == middlewares->end()) {
            current->nextMiddleware = *it;
            break;
        }
        current->nextMiddleware = *it++;
    }
    return *middlewares->begin();
}

void MiddlewareManager::handleRequest(Context *context) {
    // TODO: error handling
    this->composedMiddleware->handle_request(context);
}

void MiddlewareManager::composeMiddleware() {
    this->composedMiddleware = MiddlewareManager::compose(this->middlewares);
}

MiddlewareManager::MiddlewareManager() {
    this->middlewares = new std::list<Middleware *>;
    this->composedMiddleware = new Middleware();
}

void Middleware::handle_request(Context *context) {
    if (std::find(std::begin(methods), std::end(methods),context->request->method)==std::end(this->methods)){
        MethodNotAllowedMiddleware::handler(context);
        return;
    }
    handler(context);
    if (this->nextMiddleware != nullptr) {
        this->nextMiddleware->handle_request(context);
    }

}

Middleware::Middleware(MiddlewareFunc handler) {
    this->handler = std::move(handler);
    this->nextMiddleware = nullptr;
}

Middleware::Middleware() {
}
Middleware::Middleware(const MiddlewareFunc &function, const std::vector<std::string> &vector) {
    this->handler = function;
    this->nextMiddleware = nullptr;
    this->methods = vector;
}
