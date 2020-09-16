#include "app/App.h"
#include "routing/Router.h"
#include "json/json.hpp"
#include <iostream>
#include <thread>

int main(int argc, char *argv[]) {
    auto app = App();
    auto router = Router();
//    auto f = [](Context *context, const NextFunc &next) {
//        context->write(context->request->body["mitms"]);
//        next();
//    };
//    router.addHandler("/", f);
    router.addHandler("/", [](Context *context, const NextFunc &next) {
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        context->write(std::string("Hello"));
        next();
    });

    app.middlewareManager->middleware->push_back(router.getRoutingMiddleware());

    app.start("127.0.0.1:8000");
    return 0;
}