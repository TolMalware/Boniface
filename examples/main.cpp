#include "../app/App.h"
#include "../router/Router.h"

class MainMiddleware : public Middleware {
public:
    void handle(Context *context) override {
        context->response->body = "Hello world";
    }
};

int main() {
    auto app = App();
    auto router = Router();
    auto router1 = Router();

    router.get("/", new MainMiddleware());
    router1.post("/", [](Context *context) {
        context->response->body = "POST";
    });

    app.use(router.getMiddleware());
    app.use(router1.getMiddleware());
    app.start("127.0.0.1:8000");

    return 0;
}