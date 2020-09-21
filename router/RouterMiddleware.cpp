#include "RouterMiddleware.h"

RouterMiddleware::RouterMiddleware(Router *router) : router(router) {}

void RouterMiddleware::handle(Context *context) {
    auto layer = router->handle(context);

    if (layer == nullptr) {
        Middleware::handle(context);
    }
}
