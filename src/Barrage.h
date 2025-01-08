//
// Created by Артем on 18.11.2024.
//

#ifndef BARRAGE_H
#define BARRAGE_H

#include "Spell.h"


class Barrage : public Spell{
public:
    bool cast(Input& input) override;

    short getSpellId() override;
};


#endif //LR1_BARRAGE_H
