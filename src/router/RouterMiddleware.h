#ifndef BONIFACE_ROUTERMIDDLEWARE_H
#define BONIFACE_ROUTERMIDDLEWARE_H


#include "Router.h"

class RouterMiddleware : public Middleware {
private:
    Router *router;

public:
    explicit RouterMiddleware(Router *router);

    void handle(Context *context) override;
};


#endif //BONIFACE_ROUTERMIDDLEWARE_H
