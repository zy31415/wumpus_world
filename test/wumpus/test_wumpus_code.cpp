//
// Created by zy on 3/22/17.
//

#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include "wumpus/wumpus_code.h"

#include <iostream>

TEST_CASE("test wumpus_code: WUMPUS_BIT") {
    int code = 0;
    wc::set_wumpus(code);

    REQUIRE(code == 1 << 6);
    REQUIRE(wc::has_wumpus(code));

}

TEST_CASE("test wumpus_code: STENCH_BIT") {
    int code = 0;
    wc::set_stench(code);

    REQUIRE(code == 1 << 5);
    REQUIRE(wc::has_stench(code));

}
