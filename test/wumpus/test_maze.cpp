//
// Created by zy on 3/23/17.
//
#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include <wumpus/maze.h>


TEST_CASE("test maze creation") {
    Maze maze = Maze::factory("maze.txt");

}
