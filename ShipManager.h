#ifndef SHIPMANAGER_H
#define SHIPMANAGER_H

#include <vector>

#include "Field.h"
#include "GameExceptions.h"


class ShipManager{
public:
    ShipManager()=default;
    ShipManager(std::vector <short> shipSizes, std::vector <Ship::Orientation> shipOrientations);

    ~ShipManager();

    Ship& getShip(int n);
    void addShip(short shipLength, Ship::Orientation shipOrientation = Ship::Orientation::horizontal);
    int count();
    int countDestroyed();
    bool checkDestroyed();
    bool placeShip(Field& field, int n, int x, int y);

private:
    std::vector <Ship*> ships;
    int destroyed;
};


#endif