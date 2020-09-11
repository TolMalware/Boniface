#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <list>
#include <iostream>
#include <map>
#include <fcgio.h>


const unsigned long STDIN_MAX = 1000000;

template<class Container>
void split(const std::string &str, Container &cont) {
    std::istringstream iss(str);
    std::copy(
            std::istream_iterator<std::string>(iss),
            std::istream_iterator<std::string>(),
            std::back_inserter(cont)
    );
}

std::string convertHeaderName(const std::string &string) {
    int len = string.length();

    if (len == 0) return string;

    std::string result(string);
    std::replace(result.begin(), result.end(), '_', '-');
    std::transform(result.begin(), result.end(), result.begin(), [](u_char c) { return std::tolower(c); });

    result[0] = std::toupper(result[0]);
    for (int i = 0; i < len; ++i) {
        if (i < len - 1 && result[i] == '-') {
            result[i + 1] = std::toupper(result[i + 1]);
        }
    }

    return result;
}

std::map<std::string, std::string> *parseHeaders(char **envp) {
    auto headers = new std::map<std::string, std::string>;

    while (*(++envp)) {
        std::string entry(*envp);

        if (entry.rfind("HTTP_", 0) == 0) {
            entry.erase(0, 5);

            auto idx = entry.find('=');
            std::string name = convertHeaderName(entry.substr(0, idx));
            std::string value = entry.substr(idx, entry.length());

            headers->insert(std::pair<std::string, std::string>(name, value));
        }
    }

    return headers;
}

int parseInt(char *string) {
    try {
        return std::stoi(string);
    } catch (std::invalid_argument &) {
        return 0;
    }
}

nlohmann::json getBody(FCGX_Request *request) {
    auto len = parseInt(FCGX_GetParam("CONTENT_LENGTH", request->envp));
    char content[len];
    FCGX_GetStr(content, len, request->in);
    auto body = std::string(content);
    return nlohmann::json::parse(body.substr(0, len - body.length()));
};


std::map<std::string, std::string> *parseQuery(const std::string &querystring) {
    auto result = new std::map<std::string, std::string>;
    std::list<std::string> items;

    split(querystring, items);

    for (const auto &item : items) {
        auto idx = item.find('=');
        std::string name = item.substr(0, idx);
        std::string value = item.substr(idx, item.length());

        result->insert(std::pair<std::string, std::string>(name, value));
    }

    return result;
}
