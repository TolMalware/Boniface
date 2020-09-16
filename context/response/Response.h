#ifndef WEB_FRAMEWORK_RESPONSE_H
#define WEB_FRAMEWORK_RESPONSE_H


#include <string>
#include <map>

class Response {
public:
    int socketId = 0; // TODO: Разобраться, зачем вообще это нужно и что это

    std::map<std::string, std::string> *headers;
    int status;
    std::string body;

    std::string type;
    int length;

    Response();

    std::string get(const std::string& field) const;
    void set(const std::string& field, const std::string& value) const;
    void set(std::map<std::string, std::string>& fields);
    void append(const std::string& field, const std::string& value);
    void remove(const std::string& field) const;
    void set_status(int code);
    void send(const std::string& string);
    void send(const char *buffer, int len);
    // void send(Stream stream); TODO: Реализовать возможноность возвращать поток
    void send(const std::map<std::string, std::string>& object);
    void redirect(const std::string& url);
    std::string headers_to_string() const;
};


#endif //WEB_FRAMEWORK_RESPONSE_H
