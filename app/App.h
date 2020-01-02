#include "fcgiapp.h"
static int socketId;
class App {
    FCGX_Request request{};

public:
    explicit App(const char *address);
    void start();
};

#ifndef WEB_FRAMEWORK_APP_H
#define WEB_FRAMEWORK_APP_H

#endif //WEB_FRAMEWORK_APP_H
