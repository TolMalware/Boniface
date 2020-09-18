#include <iostream>
#include "../app/App.h"
#include "../routing/Router.h"

int main() {
    auto app = App();
    auto router = Router();
    router.addHandler("/hello", [](Context *context) {
        context->write("dfsfsfggedgwsedadsd");
    }, {"POST"});

    app.middlewareManager.middlewares->push_back(router.getRoutingMiddleware());

    app.start("127.0.0.1:8000");
    return 0;
}