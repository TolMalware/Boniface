#include "LambdaHandler.h"

LambdaHandler::LambdaHandler(HandlerFunc func) : func(func) {}

void LambdaHandler::handle(Context *context) {
    this->func(context);
}
