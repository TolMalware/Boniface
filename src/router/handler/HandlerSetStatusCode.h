#ifndef BONIFACE_HANDLERSETSTATUSCODE_H
#define BONIFACE_HANDLERSETSTATUSCODE_H


#include "../../middleware/Handler.h"

class HandlerSetStatusCode : public Handler {
private:
    int statusCode;

public:
    explicit HandlerSetStatusCode(int statusCode);

    void handle(Context *context) override;
};


#endif //BONIFACE_HANDLERSETSTATUSCODE_H
