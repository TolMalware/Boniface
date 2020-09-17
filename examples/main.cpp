#include "../app/App.h"
//#include "../routing/Router.h"

int main() {
    auto app = App();
//    auto router = Router();
//    router.addHandler("/", [](Context *context) {
//        context->write(nlohmann::json::parse(context->request->body)["mitms"].dump());
//    });
//
//    app.middlewareManager->middlewares->push_back(router.getRoutingMiddleware());

    app.start("127.0.0.1:8000");
    return 0;
}