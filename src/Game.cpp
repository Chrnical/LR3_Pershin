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
        std::cout << "New bot\n";
        gameState->generateBot();
        do {
            gameState->loadPhase();
            gameState->savePhase();
            gameState->spellCastPhase();
            gameState->shootCellPhase();
            gameState->botTurnPhase();
            gameState->printFields();
        } while (!gameState->win() && !gameState->loss());
        std::cout << "You won\n";
    } while (!gameState->loss());
    std::cout << "You lost\n";
}