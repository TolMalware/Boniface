#include "Request.h"

std::string Request::get(std::string field) {
    return this->headers->at(field);
}
