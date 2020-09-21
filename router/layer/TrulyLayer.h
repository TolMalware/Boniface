#ifndef BONIFACE_TRULYLAYER_H
#define BONIFACE_TRULYLAYER_H


#include "Layer.h"

class TrulyLayer : public Layer {
public:
    explicit TrulyLayer(Handler *handler);

    bool match(Context *context) override;
};


#endif //BONIFACE_TRULYLAYER_H
