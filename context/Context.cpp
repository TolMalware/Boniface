#include <cstring>
#include "Context.h"

Context::Context(FCGX_Request *fcgxRequest) {
    this->request = new Request(fcgxRequest);
    this->response = new Response;
    this->state = new std::map<std::string, void *>;
}

//void Context::write(const std::string &data) const {
//    std::copy(data.begin(), data.end(), response->body);
//}

Context::Context() {

}



