#include "Handler404.h"

void Handler404::handle(Context *context) {
    context->response->set_status(404);
}
