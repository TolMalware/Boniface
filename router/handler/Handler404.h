#ifndef BONIFACE_HANDLER404_H
#define BONIFACE_HANDLER404_H


#include "../../middleware/Handler.h"

class Handler404 : public Handler {
public:
    void handle(Context *context) override;
};


#endif //BONIFACE_HANDLER404_H
