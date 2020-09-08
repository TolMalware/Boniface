#ifndef WEB_FRAMEWORK_APP_H
#define WEB_FRAMEWORK_APP_H

#include "fcgiapp.h"

#include "../middleware/MiddlewareManager.h"

static int socketId;

class App {
    FCGX_Request request{};

public:
    explicit App();

    void start(const char *address);

    MiddlewareManager *middlewareManager;
};

#endif //WEB_FRAMEWORK_APP_H
