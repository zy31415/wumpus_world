//
// Created by zy on 3/22/17.
//

#include <fstream>
#include <vector>
#include <pair>

using namespace std;

#include "wumpus/maze.h"

Maze::Maze() {

    arr = new int *[Maze::size];
    for (int ii=0; ii<Maze::size; ii++)
        arr[ii] = new int [Maze::size];


}

vector<pair<size_t, size_t>> _readline(ifstream ifs) {
    size_t num_pairs;
    ifs >> num_pairs;

    vector<pair> res;

    for (int ii=0; ii<num_pairs; ii++) {
        size_t x, y;
        ifs >> x >> y;
        res.push_back(pair(x, y));
    }

    ifs.ignore(2048, '/n');

    return res;
}

Maze Maze::factory(const string& path) {
    ifstream configf;
    configf.open(path);

    configf >> size;
    configf.ignore(1024, '/n');

    size_t num_wumpus;
    configf >> num_wumpus;

    auto wumpus_pos = _readline(configf);
    auto pits_pos = _readline(configf);
    auto golds_pos = _readline(configf);

}

