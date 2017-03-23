enable_testing()

add_executable(test_wumpus_code test_wumpus_code.cpp)
target_link_libraries(test_wumpus_code wumpus)
add_test(NAME test_wumpus_code COMMAND test_wumpus_code)

configure_file(maze.txt ${CMAKE_CURRENT_BINARY_DIR}/maze.txt COPYONLY)
add_executable(test_maze test_maze.cpp)
target_link_libraries(test_maze wumpus)
add_test(NAME test_maze COMMAND test_maze)
