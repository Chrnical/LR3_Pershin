//
// Created by Артем on 24.11.2024.
//

#include "SpellManager.h"

SpellManager::SpellManager() {
    std::vector <Spell*> vector;
    vector.push_back(new DoubleDamage);
    vector.push_back(new Scan);
    vector.push_back(new Barrage);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vector.begin(), vector.end(), g);

    allSpells = {new Scan, new Barrage, new DoubleDamage};
    for(auto& i: vector){
        spells.push(i);
    }
}

void SpellManager::castSpell(Input& input) {
    if(spells.empty()){
        throw NoSpellsException();
    }
    while(!spells.front()->cast(input)){}
    spells.pop();
}

void SpellManager::addSpell() {
    int choice = rand() % 3;
    switch (choice) {
        case 0:
            spells.push(new DoubleDamage());
            break;
        case 1:
            spells.push(new Scan());
            break;
        case 2:
            spells.push(new Barrage());
            break;
    }
}

int SpellManager::countSpells() const {
    return spells.size();
}

std::queue<Spell *> &SpellManager::getQueue() {
    return spells;
}

SpellManager::SpellManager(std::queue<Spell*> &queue) {
    spells = queue;
}
