#include "ShipManager.h"


ShipManager::ShipManager(std::vector <short> shipSizes, std::vector <Ship::Orientation> shipOrientations){
    this->ships = std::vector <Ship*> ();
    for (auto i = 0; i < shipSizes.size() && i < shipOrientations.size(); i++) {
        this->ships.push_back(new Ship(shipSizes[i], shipOrientations[i]));
    }
    for (auto i = shipOrientations.size(); i < shipSizes.size(); i++) {
        this->ships.push_back(new Ship(shipSizes[i]));
    }
    destroyed = 0;
}

bool ShipManager::placeShip(Field &field, int n, int x, int y) {
    return field.placeShip(this->ships[n], x, y);
}

bool ShipManager::checkDestroyed() {
    int cnt = 0;
    for (const auto now : ships) {
        if (now->isDestroyed()) cnt++;
    }
    if (cnt != destroyed) {
        destroyed = cnt;
        return true;
    }
    return false;

}

int ShipManager::count() {
    return ships.size();
}

int ShipManager::countDestroyed() {
    this->checkDestroyed();
    return destroyed;
}

void ShipManager::addShip(short shipLength, Ship::Orientation shipOrientation) {
    if (shipLength <= 0 || shipLength > 4){
        throw ShipLengthException();
    }
    ships.push_back(new Ship(shipLength, shipOrientation));
}

Ship &ShipManager::getShip(int n) {
    if(n < 0 || n >= this->count()){
    }
    return *ships[n];
}

ShipManager::~ShipManager() {
    for(auto ship: ships){
        delete ship;
    }
}
