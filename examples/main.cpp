#include <iostream>
#include "../src/app/App.h"
#include "../src/router/Router.h"

class MainHandler : public Handler {
public:
    void handle(Context *context) override {
        context->response->send("hello world");
    }
};

int main() {
    auto app = App();
    auto router = Router();

    router.GET("/", new MainHandler());
    router.POST("/", [](Context *context) {
        context->response->send("post");
    });
    router.GET("/user", [](Context *context) {
        context->response->send("user");
    });

    app.use(router.getMiddleware());
    app.start("127.0.0.1", 8000);

    return 0;
}