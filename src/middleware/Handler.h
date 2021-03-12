#ifndef BONIFACE_HANDLER_H
#define BONIFACE_HANDLER_H


#include "../context/Context.h"

class Handler {
public:
    virtual void handle(Context *context) = 0;
};


#endif //BONIFACE_HANDLER_H
