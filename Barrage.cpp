//
// Created by Артем on 18.11.2024.
//

#include "Barrage.h"
#include <algorithm>
#include <random>


bool Barrage::cast(Input &input) {
    std::cout << "Cast Barrage\n";
    Field& field = input.getField();
    std::vector <Cell*> cells;
    for(int i = 0; i < field.getWidth(); i++){
        for(int j = 0; j < field.getHeight(); j++){
            if(field.getCell(i,j).checkSegment()) {
                cells.push_back(&field.getCell(i,j));
            }
        }
    }
    if(cells.empty()){
        return false;
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cells.begin(), cells.end(), g);

    cells[0]->getShip().shootShip(cells[0]->getSegment());
    return true;
}

short Barrage::getSpellId() {
    return 1;
}
