//
// Created by Артем on 24.11.2024.
//

#ifndef LR1_SPELLMANAGER_H
#define LR1_SPELLMANAGER_H

#include "DoubleDamage.h"
#include "Scan.h"
#include "Barrage.h"

#include <bits/stdc++.h>


class SpellManager {
public:
    SpellManager();
    SpellManager(std::queue <Spell*> &queue);

    void castSpell(Input& input);
    void addSpell();
    int countSpells() const;

    std::queue <Spell*>& getQueue();
private:
    std::queue <Spell*> spells;
    std::vector <Spell*> allSpells;
};


#endif //LR1_SPELLMANAGER_H
