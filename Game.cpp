//
// Created by Артем on 27.11.2024.
//

#include "Game.h"


Game::Game() {
    gameState = new GameState();
}

void Game::start() {
    gameState->shipPlacementPhase();
    do {
        gameState->generateBot();
        do {
            gameState->loadPhase();
            gameState->savePhase();
            gameState->spellCastPhase();
            gameState->shootCellPhase();
            gameState->botTurnPhase();
            gameState->printFields();
        } while (!gameState->win());
    } while (!gameState->loss());
}