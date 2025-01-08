#ifndef CELL_H
#define CELL_H

#include "Ship.h"

class Cell{
public:
    enum class Status {unknown, empty, ship};

    Cell();
    ~Cell();

    Cell &operator=(Cell& other);

    Status getStatus();
    short getSegment();
    Ship& getShip();
    bool checkSegment();
    void setStatus(Status status);
    void putSegment(Ship* ship, short segment);
    void shootCell(bool doubleDamage = false);
    void printCell();
private:
    Status status;
    Ship* ship;
    short segment;
};


#endif