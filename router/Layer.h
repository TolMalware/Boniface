#ifndef BONIFACE_LAYER_H
#define BONIFACE_LAYER_H


#include "../middleware/Middleware.h"
#include "../context/Context.h"

class Layer {
private:
    std::string path;
    uint8_t methods;
    Middleware *middleware;

public:
    Layer(const std::string &path, uint8_t methods, Middleware *middleware);

    bool match(Context *context);
    bool handle(Context *context);
};


#endif //BONIFACE_LAYER_H
