#ifndef BONIFACE_LAYER_H
#define BONIFACE_LAYER_H


#include <vector>
#include "../../middleware/Handler.h"
#include "../cache/CacheKey.h"

class Layer {
private:
    Handler *handler;

public:
    explicit Layer(Handler *handler);

    bool handle(Context *context);

    virtual bool match(Context *context) = 0;
    virtual std::vector<CacheKey> *getCacheKeys();
};


#endif //BONIFACE_LAYER_H
