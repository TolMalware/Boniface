#include <iostream>
#include <utility>
#include "MiddlewareManager.h"

Middleware MiddlewareManager::compose(std::list<Middleware> *middlewares) {
    auto it = middlewares->begin();
    if (!middlewares->empty()){
    while (it != middlewares->end()) {
        Middleware current = *it;
        current.nextMiddleware  =&*it;
    return *middlewares->begin();
//    return [middleware](Context *context, NextFunc next) {
//            if (middleware->empty()) return;
//
//        std::function<void(MiddlewareIterator&)> dispatch = [&dispatch, middleware, context, &next](MiddlewareIterator &it) -> void {
//            Middleware current = *it;
//            ++it;
//            MiddlewareIterator nextIt = it;
//            --it;
//
//            NextFunc nextFunc = []() {};
//
//            if (nextIt != middleware->end()) {
//                nextFunc = [&dispatch, &nextIt]() {
//                    dispatch(nextIt);
//                };
//            } else {
//                nextFunc = next;
//            }
//
//            current(context, nextFunc);
//        };
//
//        MiddlewareIterator it = middleware->begin();
//        dispatch(it);
//    };
}

void MiddlewareManager::handleRequest(Context *context){
    // TODO: error handling
    this->composedMiddleware.handle_request(context);
}

void MiddlewareManager::composeMiddleware() {
    this->composedMiddleware = MiddlewareManager::compose(this->middlewares);
}

MiddlewareManager::MiddlewareManager() {
    this->middlewares = new std::list<Middleware>;
    this->composedMiddleware = Middleware();
}

void Middleware::handle_request(Context *context){
    handler(context);
    if (this->nextMiddleware != nullptr) {
        this->nextMiddleware->handle_request(context);
    }

}

Middleware::Middleware(MiddlewareFunc handler) {
    this->handler = std::move(handler);
}

Middleware::Middleware() {
}
