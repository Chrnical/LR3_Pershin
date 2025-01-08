//
// Created by Артем on 24.11.2024.
//

#ifndef LR1_GAMEEXCEPTION_H
#define LR1_GAMEEXCEPTION_H

#include <exception>
#include <string>


class GameException : public std::exception {
public:
    GameException(const std::string& message) : message(message) {}
    const char* what() const noexcept override {
        return message.c_str();
    }

protected:
    std::string message;
};


#endif //LR1_GAMEEXCEPTION_H
