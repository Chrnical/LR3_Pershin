#include "Ship.h"


Ship::Ship(short length, Orientation orientation){
    if(length > 4 || length < 0){
        throw std::invalid_argument("Ship length must be from 1 to 4.");
    }
    this->length = length;
    this->orientation = orientation;
    this->segmentStates = std::vector <SegmentState> (length, SegmentState::intact);
}

Ship::Orientation Ship::getOrientation() const{
    return this->orientation;
}

short Ship::getLength() const{
    return this->length;
}

void Ship::shootShip(short segment, bool doubleDamage) {
    if(segmentStates[segment] == SegmentState::damaged || doubleDamage){
        segmentStates[segment] = SegmentState::destroyed;
    }else if(segmentStates[segment] == SegmentState::intact){
        segmentStates[segment] = SegmentState::damaged;
    }
}

Ship::SegmentState Ship::getSegment(short segment) {
    return segmentStates[segment];
}

bool Ship::isDestroyed() {
    for(auto i: segmentStates){
        if(i != SegmentState::destroyed){
            return false;
        }
    }
    return true;
}

void Ship::outShip(std::ostream &buffer) {
    buffer << length << " " << (int) orientation << " ";
    for(auto segment: segmentStates){
        buffer << (int) segment << " ";
    }
}

void Ship::setSegmentState(short segment, Ship::SegmentState segmentState) {
    segmentStates[segment] = segmentState;
}
