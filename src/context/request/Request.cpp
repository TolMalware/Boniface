#include "Request.h"
#include "../utils.hpp"

Request::Request(FCGX_Request *request) {
    this->headers = parseHeaders(request->envp);
    this->method = std::string(FCGX_GetParam("REQUEST_METHOD", request->envp));
    this->methodMask = methodToMask(this->method);

    this->protocol = std::string(FCGX_GetParam("REQUEST_SCHEME", request->envp));
    this->hostname = std::string(FCGX_GetParam("SERVER_NAME", request->envp));
    this->port = std::string(FCGX_GetParam("SERVER_PORT", request->envp));
    this->path = std::string(FCGX_GetParam("DOCUMENT_URI", request->envp));
    this->querystring = std::string(FCGX_GetParam("QUERY_STRING", request->envp));

    this->length = parseInt(FCGX_GetParam("CONTENT_LENGTH", request->envp));
    this->body = new char[length];
    get_body(request,this->body);

    this->host = hostname + ':' + port;
    this->origin = protocol + host;
    this->search = querystring.empty() ? "" : "?" + querystring;
    this->url = path + search;
    this->href = origin + url;

    this->type = std::string(FCGX_GetParam("CONTENT_TYPE", request->envp));

    this->query = parseQuery(querystring);
}

std::string Request::get(const std::string& field) const {
    return this->headers->at(field);
}
