//
// Created by zy on 3/22/17.
//

#ifndef WUMPUS_WUMPUS_CODE_H
#define WUMPUS_WUMPUS_CODE_H

struct WumpusCode {
    static const int WUMPUS_BIT = 6;
    static const int STENCH_BIT = 5;
    static const int PIT_BIT = 4;
    static const int BREEZE_BIT = 3;
    static const int GLITTER_BIT = 2;
    static const int BUMP_BIT = 1;
    static const int SCREAM_BIT = 0;

    static void set(int& code, const int bit);
    static bool get(const int& code, const int bit);

    static void set_wumpus(int& code);
    static bool has_wumpus(const int& code);

    static void set_stench(int& code);
    static bool has_stench(const int& code);
};

typedef struct WumpusCode wc;

#endif //WUMPUS_WUMPUS_CODE_H
