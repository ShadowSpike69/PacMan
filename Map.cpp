#include "Map.hpp"
#include <iostream>

void Map::draw() const {
    std::cout << "Drawing map of size " << width << "x" << height << "\n";
}
void Map::load() {
    grid = {
        {'W','W','W','W','W','W','W'},
        {'W','.','.','.','.','.','W'},
        {'W','.','W','W','W','.','W'},
        {'W','.','.','o','.','.','W'},
        {'W','W','W','W','W','W','W'}
    };
}

bool Map::isWall(int x, int y) const {
    return grid[y][x] == 'W';
}

bool Map::isPellet(int x, int y) const {
    return grid[y][x] == '.' || grid[y][x] == 'o';
}

void Map::eatPellet(int x, int y) {
    if (isPellet(x, y)) {
        grid[y][x] = ' ';
    }
}
