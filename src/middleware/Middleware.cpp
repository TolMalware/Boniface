#include "Middleware.h"

Middleware *Middleware::setNext(Middleware *middleware) {
    this->next = middleware;
    return middleware;
}

void Middleware::handle(Context *context) {
    if (this->next != nullptr) {
        this->next->handle(context);
    }
}
