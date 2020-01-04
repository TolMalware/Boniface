#ifndef WEB_FRAMEWORK_RESPONSE_H
#define WEB_FRAMEWORK_RESPONSE_H


#include <string>
#include <map>

class Response {
    int socketId;

    std::map<std::string, std::string> *headers;
    int status;
    char *body;

    std::string type;
    int length;

    std::string get(const std::string& field);
    void set(const std::string& field, const std::string& value);
    void set(std::map<std::string, std::string>& fields);
    void append(const std::string& field, const std::string& value);
    void remove(const std::string& field);

    void send(const std::string& string);
    void send(const char *buffer, int len);
    // void send(Stream stream); TODO: Реализовать возможноность возвращать поток
    void send(const std::map<std::string, std::string>& object);

    void redirect(const std::string& url);
};


#endif //WEB_FRAMEWORK_RESPONSE_H