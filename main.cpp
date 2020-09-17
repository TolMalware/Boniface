#include "app/App.h"
#include "routing/Router.h"
#include "json/json.hpp"
#include <iostream>
#include <thread>

int main(int argc, char *argv[]) {
    auto app = App();
    auto router = Router();
    router.addHandler("/", [](Context *context, const NextFunc &next) {
        context->write(nlohmann::json::parse(context->request->body)["mitms"].dump());
        next();
    });

    app.middlewareManager->middleware->push_back(router.getRoutingMiddleware());

    app.start("127.0.0.1:8000");
    return 0;
}