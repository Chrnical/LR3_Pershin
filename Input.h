//
// Created by Артем on 18.11.2024.
//

#ifndef INPUT_H
#define INPUT_H

#include "Field.h"
#include <iostream>


class Input {
public:
    Input();
    explicit Input(Field* field);

    void inputCoordinates();

    int getX() const;
    int getY() const;
    Field& getField() const;

    void setField(Field* field);

private:
    int x;
    int y;
    Field* field;
};


#endif //LR1_INPUT_H
