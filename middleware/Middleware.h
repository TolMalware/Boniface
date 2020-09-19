#ifndef BONIFACE_MIDDLEWARE_H
#define BONIFACE_MIDDLEWARE_H


#include "../context/Context.h"

class Middleware {
private:
    Middleware *next = nullptr;

public:
    virtual void handle(Context *context);

    Middleware* setNext(Middleware *middleware);
};


#endif //BONIFACE_MIDDLEWARE_H
