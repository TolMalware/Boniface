#ifndef BONIFACE_LAYER_H
#define BONIFACE_LAYER_H


#include <vector>
#include "../middleware/Middleware.h"
#include "../context/Context.h"
#include "CacheKey.h"

class Layer {
private:
    Middleware *middleware;

public:
    explicit Layer(Middleware *middleware);

    bool handle(Context *context);

    virtual bool match(Context *context) = 0;
    virtual std::vector<CacheKey> *getCacheKeys();
};


#endif //BONIFACE_LAYER_H
