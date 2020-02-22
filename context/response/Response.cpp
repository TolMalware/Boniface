#include "Response.h"

Response::Response() {
    this->headers = new std::map<std::string, std::string>;
    this->status = 200;
    this->body = "";
    this->length = 0;
}

std::string Response::get(const std::string& field) {
    return this->headers->at(field);
}

void Response::set(const std::string& field, const std::string& value) {
    this->headers->insert(std::pair<std::string, std::string>(field, value));
}

void Response::set(std::map<std::string, std::string>& fields) {
    this->headers = &fields;
}

void Response::append(const std::string& field, const std::string& value) {
    if (this->headers->contains(field)) {
        std::string headerValue = this->get(field);

        this->set(field, value + ";" + field);
    } else {
        this->set(field, value);
    }
}

void Response::remove(const std::string& field) {
    auto it = this->headers->find(field);

    if (it != this->headers->end()) {
        this->headers->erase(it);
    }
}

void Response::send(const std::string& string) {
    this->body = const_cast<char *>(string.c_str());
    this->length = string.length();
}

void Response::send(const char *buffer, int len) {
    this->body = const_cast<char *>(buffer);
    this->length = len;
}

void Response::send(const std::map<std::string, std::string>& object) {
    // TODO: stringify json
}

void Response::set_status(int code){
     this -> append("Status",std::to_string(code));
}
//void Response::redirect(const std::string& url) {
//    this->send(301);
//    this->set("Location", url);
//}
