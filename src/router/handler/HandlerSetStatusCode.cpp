#include "HandlerSetStatusCode.h"

HandlerSetStatusCode::HandlerSetStatusCode(int statusCode) : statusCode(statusCode) {}

void HandlerSetStatusCode::handle(Context *context) {
    context->response->set_status(this->statusCode);
}
