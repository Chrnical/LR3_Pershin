//
// Created by Артем on 18.11.2024.
//

#include "DoubleDamage.h"

bool DoubleDamage::cast(Input &input) {
    std::cout << "Cast DoubleDamage\n";
    input.getField().setDoubleDamage(true);
    return true;
}

short DoubleDamage::getSpellId() {
    return 2;
}
