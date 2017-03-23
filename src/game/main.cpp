//
// Created by zy on 3/22/17.
//
#include <iostream>

# include "wumpus/wumpus_world.h"

int main() {

    WumpusWorld game;

    game.start();

    while (game.get_status() == GAME_STATUS::CONTINUE) {
        cout << "You action: ";
        // deal with action;
    }

    // Handle existing:

    return 0;
}


