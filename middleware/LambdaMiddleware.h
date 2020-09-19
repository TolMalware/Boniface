#ifndef BONIFACE_LAMBDAMIDDLEWARE_H
#define BONIFACE_LAMBDAMIDDLEWARE_H


#include <functional>
#include "Middleware.h"

using MiddlewareFunc = std::function<void(Context*)>;

class LambdaMiddleware : public Middleware {
private:
    MiddlewareFunc &func;

public:
    explicit LambdaMiddleware(MiddlewareFunc &func);

    void handle(Context *context) override;
};


#endif //BONIFACE_LAMBDAMIDDLEWARE_H
