#ifndef WEB_FRAMEWORK_APP_H
#define WEB_FRAMEWORK_APP_H

#include "fcgiapp.h"
#include "../middleware/MiddlewareManager.h"

static int socketId;

class App {
    MiddlewareManager *middlewareManager;
    FCGX_Request request;

public:
    explicit App();

    void start(const char *address);
};

#endif //WEB_FRAMEWORK_APP_H
