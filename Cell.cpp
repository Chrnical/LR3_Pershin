#include "Cell.h"
#include <iostream>


Cell::Cell(){
    this->status = Status::unknown;
    this->ship = nullptr;
    this->segment = -1;
}

Cell::Status Cell::getStatus(){
    return this->status;
}

void Cell::setStatus(Cell::Status status){
    this->status = status;
}

void Cell::putSegment(Ship* ship, short segment){
    this->ship = ship;
    this->segment = segment;
}

Cell::~Cell(){
    if(this->ship != nullptr){
        delete this->ship;
    }
}


void Cell::shootCell(bool doubleDamage){
    if(this->status == Status::ship){
        this->ship->shootShip(segment, doubleDamage);
    }
    if(this->status == Status::unknown){
        if(this->ship != nullptr){
            this->status = Status::ship;
            this->ship->shootShip(segment, doubleDamage);
        }else{
            this->status = Status::empty;
        }
    }
}

void Cell::printCell(){
    if(status == Status::unknown){
        std::cout << " ";
        return;
    }
    if(status == Status::empty){
        std::cout << ".";
        return;
    }
    if(ship->getSegment(segment) == Ship::SegmentState::intact){
        std::cout << "2";
    }else if(ship->getSegment(segment) == Ship::SegmentState::damaged){
        std::cout << "1";
    }else if(ship->getSegment(segment) == Ship::SegmentState::destroyed){
        std::cout << "0";
    }
}

short Cell::getSegment(){
    return this->segment;
}

bool Cell::checkSegment(){
    if(this->ship == nullptr){
        return false;
    }
    return true;
}

Cell &Cell::operator=(Cell& other) {
    this->status = other.status;
    return *this;
}

Ship &Cell::getShip() {
    return *ship;
}
