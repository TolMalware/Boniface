#include <iostream>
#include "../app/App.h"
#include "../routing/Router.h"
#include "user.h"
#include "../json/json.hpp"

int main() {
    auto app = App();
    auto router = Router();
    router.addHandler("/", [](Context *context) {
        auto data = nlohmann::json::parse(context->request->body);
        auto u = User::create(data["login"], data["password"]);
        std::map<std::string, std::string> result = {{"login",    u.login},
                                                     {"password", u.password}};
        context->write(nlohmann::json(result).dump());
        context->response->set_status(201);
    }, {"POST"});

    router.addHandler("/get_user", [](Context *context) {
        auto data = nlohmann::json::parse(context->request->body);
        try {
            User u = User::get(data["login"], data["password"]);
            std::map<std::string, std::string> result = {{"login",    u.login},
                                                         {"password", u.password}};
            context->write(nlohmann::json(result).dump());
        } catch (UserDoesNotExist e) {
            context->write(e.what());
        }
    });

    app.middlewareManager.middlewares->push_back(router.getRoutingMiddleware());

    app.start("127.0.0.1:8000");
    return 0;
}