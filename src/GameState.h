//
// Created by Артем on 28.11.2024.
//

#ifndef LR1_GAMESTATE_H
#define LR1_GAMESTATE_H

#include <bits/stdc++.h>
#include "Field.h"
#include "ShipManager.h"
#include "SpellManager.h"


class GameState {
public:
    GameState();
    GameState(int w, int h);


    Field& getPlayerField() const;
    Field& getBotField() const;
    ShipManager& getPlayerShipManager() const;
    ShipManager& getBotShipManager() const;
    SpellManager& getSpellManager() const;

    void shipPlacementPhase();
    void spellCastPhase();
    void shootCellPhase();
    void botTurnPhase();
    void savePhase() const;
    bool loadPhase();

    void printFields();
    void generateBot();
    bool loss();
    bool win();

private:
    Input* input;
    int fieldWidth;
    int fieldHeight;
    Field* playerField;
    Field* botField;
    ShipManager* playerShipManager;
    ShipManager* botShipManager;
    SpellManager* spellManager;
};

std::ostream& operator<<(std::ostream& os, const GameState& gameState);

std::istream& operator>>(std::istream& is, GameState& gameState);

#endif //LR1_GAMESTATE_H
