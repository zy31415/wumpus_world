//
// Created by zy on 3/22/17.
//

#ifndef WUMPUS_MAZE_H
#define WUMPUS_MAZE_H


#include <cstddef>
#include <string>

using namespace std;

class Maze {
    static size_t size;

    int **arr;

    size_t num_wumps, num_pits, num_golds;

    // _read and _mark functions are auxiliary functions used to parse maze configuration file.
    static void _read(ifstream& configf, Maze& maze, size_t & count, const int bit);
    static void _mark(Maze& maze, size_t x, size_t y, const int bit);

public:
    Maze();

    // Factory function that reads a maze configuration file and return a maze object.
    static Maze factory(const string& path);

};

#endif //WUMPUS_MAZE_H
