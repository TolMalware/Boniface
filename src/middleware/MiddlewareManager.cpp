#include "MiddlewareManager.h"

void MiddlewareManager::use(Middleware *middleware) {
    if (this->head == nullptr) {
        this->head = middleware;
    } else {
        this->tail->setNext(middleware);
    }

    this->tail = middleware;
}

void MiddlewareManager::handle(Context *context) {
    if (this->head != nullptr) {
        this->head->handle(context);
    }
}
