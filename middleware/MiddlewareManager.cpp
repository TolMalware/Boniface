#include <iostream>
#include <utility>
#include "MiddlewareManager.h"

Middleware MiddlewareManager::compose(std::list<Middleware> *middlewares) {
//    auto it = middlewares->begin();
//    if (!middlewares->empty()){
//        exit(1);
//    while (it != middlewares->end()) {
//        exit(1);
//        Middleware current = *it;
//        exit(1);
//        current.nextMiddleware  =&*it;
//        exit(1);
////            ++it;
////            auto nextIt = it;
////            --it;
////        *it->nextMiddleware = *it++;
//    }}
//    exit(2);
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
//    std::cout << this->methods << std::endl;
    handler = [this](Context *context) { context->write(std::string("hi")); };
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
