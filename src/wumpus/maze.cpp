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


void Maze::_read(ifstream& configf, int **arr, size_t & count, const int property_bit) {
    /*
     *  configf: input file stream
     *  arr: 2D array use to record map status
     *  count: number of position pairs that are going to be read in.
     *  property_bit: the property that is being read in.
     */

    configf >> count;

    for (int ii=0; ii< count; ii++) {
        size_t x, y;
        configf >> x >> y;
        _mark(arr, x, y, property_bit);
    }

    configf.ignore(2048, '\n');
}

void Maze::_mark(int **arr, size_t x, size_t y, const int property_bit) {

    if (x >= size || y >= size)
        throw new out_of_range("Out of range.");

    wc::set(arr[x][y], property_bit);

    // For wumpus and pit, mark neighbors for stench and breeze, respectively
    if (property_bit == WumpusCode::WUMPUS_BIT || property_bit == WumpusCode::PIT_BIT) {
        if (x >= 1)
            wc::set(arr[x - 1][y], property_bit-1);

        if (x + 1 < size)
            wc::set(arr[x + 1][y], property_bit-1);

        if (y >= 1)
            wc::set(arr[x][y - 1], property_bit-1);

        if (y + 1 < size)
            wc::set(arr[x][y + 1], property_bit-1);
    }
}


Maze Maze::factory(const string& path) {

    ifstream configf(path);

    if (!configf)
        throw domain_error("Bad Input.");

    configf >> size;
    configf.ignore(1024, '\n');

    Maze maze;
    _read(configf, maze.arr, maze.num_wumps, WumpusCode::WUMPUS_BIT);
    _read(configf, maze.arr, maze.num_pits, WumpusCode::PIT_BIT);
    _read(configf, maze.arr, maze.num_golds, WumpusCode::GLITTER_BIT);

    return maze;
}
