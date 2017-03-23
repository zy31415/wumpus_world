//
// Created by zy on 3/22/17.
//

/*
 * A bit-wise integer code to record information about each room of the maze:
 *
 * {Wumpus, Stench, Pit, Breeze, Glitter, Bump, Scream}
 *
 */

#include <glob.h>
#include "wumpus/wumpus_code.h"

void WumpusCode::set(int& code, const int bit) {
    code |= 1 << bit;
}

bool WumpusCode::get(const int& code, const int bit) {
    return (bool) (code >> bit & 1);
}

void WumpusCode::set_wumpus(int& code) {
    WumpusCode::set(code, WUMPUS_BIT);
}

bool WumpusCode::has_wumpus(const int &code) {
    return WumpusCode::get(code, WUMPUS_BIT);
}

void WumpusCode::set_stench(int& code) {
    WumpusCode::set(code, STENCH_BIT);
}

bool WumpusCode::has_stench(const int &code) {
    return WumpusCode::get(code, STENCH_BIT);
}
