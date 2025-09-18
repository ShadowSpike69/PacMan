#include "Map.hpp"
#include <iostream>

void Map::load() {
    grid = {
        {'W','W','W','W','W','W','W'},
        {'W','.','.','.','.','.','W'},
        {'W','.','W','W','W','.','W'},
        {'W','.','.','o','.','.','W'},
        {'W','W','W','W','W','W','W'}
    };
}

void Map::draw() const {
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
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
