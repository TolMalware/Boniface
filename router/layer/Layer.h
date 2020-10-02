#ifndef BONIFACE_LAYER_H
#define BONIFACE_LAYER_H


#include <vector>
#include "../../middleware/Handler.h"

class Layer {
private:
    Handler *handler;

public:
    explicit Layer(Handler *handler);

    Layer *handle(Context *context);

    virtual bool match(Context *context) = 0;
    virtual bool matchUrl(Context *context);
};


#endif //BONIFACE_LAYER_H
