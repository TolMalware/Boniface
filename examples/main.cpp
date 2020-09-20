#include "../app/App.h"
#include "../router/Router.h"

class MainHandler : public Middleware {
public:
    void handle(Context *context) override {
        context->response->send("hello world");
    }
};

int main() {
    auto app = App();
    auto router = Router();
    auto router1 = Router();

    router.get("/", new MainHandler());
    router1.post("/", [](Context *context) {
        context->response->send("post");
    });

    app.use(router.getMiddleware());
    app.use(router1.getMiddleware());
    app.start("127.0.0.1:8000");

    return 0;
}