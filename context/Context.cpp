#include "Context.h"

Context::Context(FCGX_Request* fcgxRequest) {
    this->request = new Request(fcgxRequest);
    this->response = new Response;
    this->state = new std::map<std::string, void*>;
}

void Context::write(const nlohmann::json& data) {
    this->response->body = data.dump();
}

void Context::write(const std::string& data) {
    this->response->body = data;
}



