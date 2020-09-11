#include "app/App.h"
#include "routing/Router.h"
#include <iostream>

int main() {
    auto app = App();
    auto router = Router();
    auto f = [](Context *context, const NextFunc &next) {
        context->response->body = const_cast<char *>("Ylii Pelevin TOPCHEG!");
        next();
    };
    router.addHandler("/", f);
    router.addHandler("/hello", [](Context *context, const NextFunc &next) {
        context->response->body = const_cast<char *>("Hello P");
        next();
    });

    app.middlewareManager->middleware->push_back(router.getRoutingMiddleware());
    app.start("127.0.0.1:8000");
    return 0;
}