#ifndef BONIFACE_MIDDLEWARE_H
#define BONIFACE_MIDDLEWARE_H


#include "Handler.h"

class Middleware : Handler {
private:
    Middleware *next = nullptr;

public:
    void handle(Context *context) override;

    Middleware* setNext(Middleware *middleware);
};


#endif //BONIFACE_MIDDLEWARE_H
