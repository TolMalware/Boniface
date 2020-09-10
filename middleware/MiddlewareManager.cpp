#include <iostream>
#include "MiddlewareManager.h"

MiddlewareManager::MiddlewareManager() {
    this->middleware = new std::list<MiddlewareFunc>;
}

MiddlewareFunc MiddlewareManager::compose(std::list<MiddlewareFunc> *middleware) {
    return [middleware](Context *context, NextFunc next) {
            if (middleware->empty()) return;

        std::function<void(MiddlewareIterator&)> dispatch = [&dispatch, middleware, context, &next](MiddlewareIterator &it) -> void {
            MiddlewareFunc current = *it;
            ++it;
            MiddlewareIterator nextIt = it;
            --it;

            NextFunc nextFunc = []() {};

            if (nextIt != middleware->end()) {
                nextFunc = [&dispatch, &nextIt]() {
                    dispatch(nextIt);
                };
            } else {
                nextFunc = next;
            }

            current(context, nextFunc);
        };

        MiddlewareIterator it = middleware->begin();
        dispatch(it);
    };
}

void MiddlewareManager::handleRequest(Context *context) {
    // TODO: error handling
    this->composedMiddleware(context, []() {
        std::cout << "Request handled" << std::endl;
    });
}

void MiddlewareManager::composeMiddleware() {
    this->composedMiddleware = MiddlewareManager::compose(this->middleware);
}
