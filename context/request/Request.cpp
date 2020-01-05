#include "Request.h"
#include "../utils.hpp"

Request::Request(FCGX_Request *request) {
    this->headers = parseHeaders(request->envp);
    this->method = std::string(FCGX_GetParam("REQUEST_METHOD", request->envp));

    this->protocol = std::string(FCGX_GetParam("REQUEST_SCHEME", request->envp));
    this->hostname = std::string(FCGX_GetParam("SERVER_NAME", request->envp));
    this->port = std::string(FCGX_GetParam("SERVER_PORT", request->envp));
    this->path = std::string(FCGX_GetParam("DOCUMENT_URI", request->envp));
    this->querystring = std::string(FCGX_GetParam("QUERY_STRING", request->envp));

    this->host = hostname + ':' + port;
    this->origin = protocol + host;
    this->search = "?" + querystring;
    this->url = path + search;
    this->href = origin + url;

    this->length = parseInt(FCGX_GetParam("CONTENT_LENGTH", request->envp));
    this->type = std::string(FCGX_GetParam("CONTENT_TYPE", request->envp));

    this->query = parseQuery(querystring);

    int len;
    char *buf = new char[1024];
    while ((len = FCGX_GetStr(buf, 1024, request->in)) > 0) {
        for (int j = 0; j < len; ++j) {
            // TODO: Добавить эти байты в body
        }
    }
}

std::string Request::get(std::string field) {
    return this->headers->at(field);
}
