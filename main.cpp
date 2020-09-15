#include "app/App.h"
#include "routing/Router.h"
#include "json/json.hpp"
#include <iostream>

int main() {
    auto app = App();
    auto router = Router();
    auto f = [](Context *context, const NextFunc &next) {
        context->write(context->request->body["mitms"]);
        next();
    };
//    router.addHandler("/", f);
    router.addHandler("/", [](Context *context, const NextFunc &next) {
        context->response->body = const_cast<char *>("Hello P");
        next();
    },{"POST"});

    app.middlewareManager->middleware->push_back(router.getRoutingMiddleware());
    app.start("127.0.0.1:8000");
    return 0;
}