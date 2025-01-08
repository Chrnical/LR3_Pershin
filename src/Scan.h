//
// Created by Артем on 18.11.2024.
//

#ifndef SCAN_H
#define SCAN_H

#include "Spell.h"


class Scan : public Spell {
public:
    bool cast(Input& input) override;

    short getSpellId() override;
};


#endif //LR1_SCAN_H
