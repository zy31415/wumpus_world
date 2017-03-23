//
// Created by zy on 3/22/17.
//

#ifndef WUMPUS_WORLD_H
#define WUMPUS_WORLD_H

#include <set>

using namespace std;

enum GAME_STATUS {CONTINUE, ABORT};

class WumpusWorld {

    size_t arrows;
    set<int, int> captain_pos;

    int scores;

public:

    // change direction, no returns.
    void turn_left();
    void turn_right();

    // return perception of the move
    int move();

    // return perception of the move
    int grab();

    // return perception of the move
    int shoot();

    void start();

    GAME_STATUS get_status();

};


#endif //WUMPUS_WORLD_H
