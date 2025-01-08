//
// Created by Артем on 18.11.2024.
//

#ifndef SPELL_H
#define SPELL_H

#include "Input.h"


class Spell {
public:
    Spell() = default;
    virtual bool cast(Input& input);
    virtual short getSpellId();
};


#endif //LR1_SPELL_H
