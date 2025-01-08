//
// Created by Артем on 18.11.2024.
//

#include "Scan.h"

bool Scan::cast(Input &input) {
    std::cout << "Cast Scan\n";
    input.inputCoordinates();
    int x = input.getX();
    int y = input.getY();
    if(x < 0 || y < 0 || x + 1 >= input.getField().getWidth() || y + 1 >= input.getField().getWidth()){
        throw OutOfBoundsException();
        return false;
    }
    bool res = false;
    for(int i = x; i < x + 2; i++){
        for(int j = y; j < y + 2; j++){
            if(input.getField().getCell(i,j).checkSegment()){
                res = true;
            }
        }
    }
    if(res){
        std::cout << "Scan successful.\n";
        return true;
    }
    std::cout << "Scan unsuccessful.\n";
    return true;
}

short Scan::getSpellId() {
    return 0;
}
