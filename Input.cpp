//
// Created by Артем on 18.11.2024.
//

#include "Input.h"

int Input::getX() const {
    return x;
}

int Input::getY() const {
    return y;
}

Field& Input::getField() const {
    return *field;
}

void Input::inputCoordinates() {
    std::cout << "Input coordinates (<x> <y>):";
    std::cin >> x >> y;
}

Input::Input(Field* field) {
    this->field = field;
}

Input::Input() {
    this->field = nullptr;
}

void Input::setField(Field* field) {
    this->field = field;
}


