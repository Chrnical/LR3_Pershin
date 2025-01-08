//
// Created by Артем on 24.11.2024.
//

#ifndef LR1_GAMEEXCEPTIONS_H
#define LR1_GAMEEXCEPTIONS_H

#include "GameException.h"


class NoSpellsException : public GameException {
public:
    NoSpellsException() : GameException("No spells available.") {}
};

class ShipPlacementException : public GameException {
public:
    ShipPlacementException() : GameException("Invalid ship placement.") {}
};

class OutOfBoundsException : public GameException {
public:
    OutOfBoundsException() : GameException("Coordinates out of bounds.") {}
};

class ShipLengthException : public GameException {
public:
    ShipLengthException() : GameException("Invalid ship length.") {}
};

#endif //LR1_GAMEEXCEPTIONS_H
