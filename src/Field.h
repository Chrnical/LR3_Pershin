#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <iostream>

#include "Cell.h"
#include "GameExceptions.h"


class Field{
public:
    Field(int width, int height);
    ~Field() = default;

    // Копирование
    Field(Field& source);
    Field& operator=(Field& source);

    // Перемещение
    Field(Field&& source);
    Field& operator=(Field&& source);


    int getWidth() const;
    int getHeight() const;
    bool getDoubleDamage();
    void setDoubleDamage(bool a);
    bool placeShip(Ship* ship, int x, int y);
    bool shoot(int x, int y);
    bool ifEmpty(int x, int y);
    void printField();
    Cell& getCell(int x, int y);
    void show();

    void outShips(std::ostream &buffer);
    void outCells(std::ostream &buffer);
private:
    int width;
    int height;
    std::vector <std::vector <Cell> > cells;
    bool doubleDamage = false;
};


#endif