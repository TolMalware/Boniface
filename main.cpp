#include "app/App.h"

int main() {
    auto app = App();
    app.start("127.0.0.1:8000");
    return 0;
}