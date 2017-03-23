//
// Created by zy on 3/22/17.
//

#include <fstream>
#include <vector>
#include <utility>
#include <stdexcept>

using namespace std;

#include "wumpus/wumpus_code.h"

#include "wumpus/maze.h"


size_t Maze::size = 4;

Maze::Maze() {
    arr = new int *[Maze::size];
    for (int ii=0; ii<Maze::size; ii++)
        arr[ii] = new int [Maze::size]();
}


void Maze::_read(ifstream& configf, Maze& maze, size_t & count, const int bit) {
    configf >> count;

    for (int ii=0; ii< count; ii++) {
        size_t x, y;
        configf >> x >> y;
        _mark(maze, x, y, bit);
    }

    configf.ignore(2048, '\n');
}

void Maze::_mark(Maze& maze, size_t x, size_t y, const int bit) {

    if (x >= size || y >= size)
        throw new out_of_range("Out of range.");

    wc::set(maze.arr[x][y], bit);

    // For wumpus and pit, mark neighbor for stench and breeze, respectively
    if (bit == WumpusCode::WUMPUS_BIT || bit == WumpusCode::PIT_BIT) {
        if (x >= 1)
            wc::set(maze.arr[x - 1][y], bit-1);

        if (x + 1 < size)
            wc::set(maze.arr[x + 1][y], bit-1);

        if (y >= 1)
            wc::set(maze.arr[x][y - 1], bit-1);

        if (y + 1 < size)
            wc::set(maze.arr[x][y + 1], bit-1);
    }
}


Maze Maze::factory(const string& path) {

    ifstream configf(path);

    if (!configf)
        throw domain_error("Bad Input.");

    configf >> size;
    configf.ignore(1024, '\n');

    Maze maze;
    _read(configf, maze, maze.num_wumps, WumpusCode::WUMPUS_BIT);
    _read(configf, maze, maze.num_pits, WumpusCode::PIT_BIT);
    _read(configf, maze, maze.num_golds, WumpusCode::GLITTER_BIT);

    return maze;
}

