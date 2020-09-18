#include <iostream>
#include "../app/App.h"
//#include "../routing/Router.h"


void test_func1(Context *context){
  context->write(std::string("HELLO FROM MIDDLEWARE"));

}
void test_func2(Context *context){
  context->response->body+="HELLO FROM MIDDLEWARE12";

}

int main() {
    auto app = App();
    app.middlewareManager.middlewares->emplace_front(new Middleware(test_func1));
    app.middlewareManager.middlewares->emplace_back(new Middleware(test_func2));
//    auto router = Router();
//    router.addHandler("/", [](Context *context) {
//        context->write(nlohmann::json::parse(context->request->body)["mitms"].dump());
//    });
//
//    app.middlewareManager->middlewares->push_back(router.getRoutingMiddleware());

    app.start("127.0.0.1:8000");
    return 0;
}