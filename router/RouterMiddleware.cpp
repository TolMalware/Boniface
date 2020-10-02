#include "RouterMiddleware.h"

RouterMiddleware::RouterMiddleware(Router *router) : router(router) {}

void RouterMiddleware::handle(Context *context) {
    bool handled = router->handle(context);

    if (!handled) {
        Middleware::handle(context);
    }
}
