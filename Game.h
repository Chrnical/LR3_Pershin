//
// Created by Артем on 27.11.2024.
//

#ifndef LR1_GAME_H
#define LR1_GAME_H


#include <bits/stdc++.h>
#include "GameState.h"


class Game {
public:
    Game();

    void start();
private:
    GameState* gameState;
};


#endif //LR1_GAME_H
