#include <iostream>
#include "../app/App.h"
#include "../routing/Router.h"
#include "user.h"

int main() {

    auto u = User::get("hello","password");
    auto g = User::create("new user","password");
    W.commit();
    std::cout<<g.login;
    exit(120);
    auto app = App();
    auto router = Router();
    router.addHandler("/hello", [](Context *context) {
        context->write("dfsfsfggedgwsedadsd");
    }, {"POST"});

    app.middlewareManager.middlewares->push_back(router.getRoutingMiddleware());

    app.start("127.0.0.1:8000");
    return 0;
}