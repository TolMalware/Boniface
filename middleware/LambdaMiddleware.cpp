#include "LambdaMiddleware.h"

LambdaMiddleware::LambdaMiddleware(MiddlewareFunc &func) : func(func) {}

void LambdaMiddleware::handle(Context *context) {
    this->func(context);
    Middleware::handle(context);
}
