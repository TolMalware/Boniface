#ifndef BONIFACE_STRICTLAYER_H
#define BONIFACE_STRICTLAYER_H


#include "Layer.h"

class StrictLayer : public Layer {
private:
    const std::string path;
    const uint8_t methods;

public:
    StrictLayer(std::string path, uint8_t methods, Handler *handler);

    bool match(Context *context) override;
    std::vector<CacheKey> *getCacheKeys() override;
};


#endif //BONIFACE_STRICTLAYER_H
