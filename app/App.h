#ifndef WEB_FRAMEWORK_APP_H
#define WEB_FRAMEWORK_APP_H

#include "fcgiapp.h"

#include "../middleware/MiddlewareManager.h"

static int socketId;

class App {

public:
    App();

    MiddlewareManager middlewareManager;

    void run();
    void start(const char *address);
};

#endif //WEB_FRAMEWORK_APP_H
