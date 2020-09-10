#include <iostream>
#include "MiddlewareManager.h"

MiddlewareManager::MiddlewareManager() {
    this->middlewares = new std::list<Middleware>;
}

Middleware MiddlewareManager::compose(std::list<Middleware> *middlewares) {
    if (middlewares->empty()) {
        return Middleware();
    }
    Context *context;
    auto next = Middleware();
    std::function<void(MiddlewareIterator &)> dispatch = [&dispatch, &middlewares, &context](MiddlewareIterator &it) -> Middleware {
        Middleware nextMiddleware;
        Middleware current = *it;
        ++it;
        MiddlewareIterator nextIt = it;
        --it;

        if (nextIt != middlewares->end()) {
            nextMiddleware = [&dispatch, &nextIt]() {
                dispatch(nextIt);
            };
        } else {
            nextMiddleware = next;
        }

        current.handler(context, nextMiddleware);
    };

    MiddlewareIterator it = middlewares->begin();
    dispatch(it);
    return Middleware();

}
//    return [middlewares](Context *context, Middleware middleware) {
//            if (middlewares->empty()) return;
//
//        std::function<void(MiddlewareIterator&)> dispatch = [&dispatch, middleware, context, &next](MiddlewareIterator &it) -> void {
//            Middleware current = *it;
//            ++it;
//            MiddlewareIterator nextIt = it;
//            --it;
//
//            Middleware nextMiddleware;
//
//            if (nextIt != middleware->end()) {
//                nextMiddleware= [&dispatch, &nextIt]() {
//                    dispatch(nextIt);
//                };
//            } else {
//                nextMiddleware = next;
//            }
//
//            current(context, nextMiddleware);
//        };
//
//        MiddlewareIterator it = middleware->begin();
//        dispatch(it);
//    };
//}

void MiddlewareManager::handleRequest(Context *context) {
    // TODO: error handling
    this->composedMiddlewares.handler(context, []() {
        std::cout << "Request handled" << std::endl;
    });
}

void MiddlewareManager::composeMiddleware() {
    this->composedMiddlewares = MiddlewareManager::compose(this->middlewares);
}
