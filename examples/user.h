//
// Created by danil on 19.09.2020.
//

#ifndef BONIFACE_USER_H
#define BONIFACE_USER_H

#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include <utility>

auto C = new pqxx::connection("postgresql://root:123456@localhost/boniface");

struct UserDoesNotExist : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "UserDoesNotExist";
    }
};

class User {

    User(std::string login, std::string password) {
        this->login = std::move(login);
        this->password = std::move(password);
    }

public:
    static User get(const std::string& login, const std::string& password) {
        pqxx::work W{*C};
        std::stringstream ss;
        ss << "SELECT login, password FROM public.user where login=" << W.quote(login) << " and password="
           << W.quote(password);
        pqxx::result R{W.exec(ss)};
        if (!R.empty()) {
            return User(login, password);
        } else {
            throw UserDoesNotExist();
        }

    }

    static User create(const std::string &login, const std::string &password) {
        pqxx::work W{*C};
        C->prepare("create_user", "INSERT INTO public.user (id, login, password) VALUES (DEFAULT, $1, $2)");
        W.exec_prepared("create_user", login, password);
        W.commit();
        return User::get(login, password);
    }

    std::string password;
    std::string login;
};

#endif //BONIFACE_USER_H
