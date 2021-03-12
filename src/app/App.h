#ifndef WEB_FRAMEWORK_APP_H
#define WEB_FRAMEWORK_APP_H

#include "fcgiapp.h"

#include "../middleware/MiddlewareManager.h"

class App {
private:
    MiddlewareManager middlewareManager;

public:
    App();

    App& use(Middleware *middleware);
    void start(const std::string& host, int port);
};

#endif //WEB_FRAMEWORK_APP_H
