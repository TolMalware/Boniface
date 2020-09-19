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
pqxx::work W{*C};

//
//std::cout << "Found " << R.size() << "employees:\n";
//for (auto row: R)
//std::cout << row[0].c_str() << " "<< row[1].c_str()<<'\n';

struct UserDoesNotExist : public std::exception {
    const char *what() const throw() {
        return "UserDoesNotExist";
    }
};

class User {

    User(std::string login, std::string password) {
        login = login;
        password = password;
    }

public:
    static User get(std::string login, std::string password) {
        std::stringstream ss;
        ss << "SELECT login, password FROM public.user where login=" << W.quote(login) << " and password="
           << W.quote(password);
        pqxx::result R{W.exec(ss)};
//        W.commit();
        if (!R.empty()) {
            return User(std::move(login), std::move(password));
        } else {
            throw UserDoesNotExist();
        }

    }

    static User create(const std::string &login, const std::string &password) {
        std::stringstream ss;
        "INSERT INTO public.\"user\" (id, login, password) VALUES (DEFAULT, 'hello', 'password')";
        C->prepare("create_user", "INSERT INTO public.user (id, login, password) VALUES (DEFAULT, $1, $2)");
        W.exec_prepared("create_user", login, password);

//        W.commit();
//        pqxx::result R{};

        return User::get(login, password);
    }

    std::string password;
    std::string login;
};

#endif //BONIFACE_USER_H
