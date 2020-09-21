#include "../app/App.h"
#include "../router/Router.h"

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
    router.POST(
        "/", [](Context *context) {
            context->response->send("post");
        }
    );

    app.use(router.getMiddleware());
    app.start("127.0.0.1:8000");

    return 0;
}