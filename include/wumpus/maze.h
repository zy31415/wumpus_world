//
// Created by zy on 3/22/17.
//

#ifndef WUMPUS_MAZE_H
#define WUMPUS_MAZE_H


#include <cstddef>
#include <string>

using namespace std;

class Maze {
    static size_t size = 4;

    int **arr;

public:
    Maze();

    static Maze factory(const string& path);

};

#endif //WUMPUS_MAZE_H
