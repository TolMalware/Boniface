#ifndef BONIFACE_LAMBDAHANDLER_H
#define BONIFACE_LAMBDAHANDLER_H


#include <functional>
#include "../middleware/Handler.h"

using HandlerFunc = std::function<void(Context*)>;

class LambdaHandler : public Handler {
private:
    HandlerFunc &func;

public:
    explicit LambdaHandler(HandlerFunc &func);

    void handle(Context *context) override;
};


#endif //BONIFACE_LAMBDAHANDLER_H
