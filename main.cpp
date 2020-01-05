#include "app/App.h"

int main() {
    auto app = App("127.0.0.1:8000");
    app.start();
    return 0;
}