//
// Created by Артем on 18.11.2024.
//

#ifndef DOUBLEDAMAGE_H
#define DOUBLEDAMAGE_H

#include "Spell.h"

class DoubleDamage : public Spell{
public:
    bool cast(Input& input) override;

    short getSpellId() override;
};


#endif //LR1_DOUBLEDAMAGE_H