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
int Map::getWidth() const { return width; }
int Map::getHeight() const { return height; }
void Map::setWidth(int w) { width = w; }
void Map::setHeight(int h) { height = h; }
const auto& Map::getGrid() const { return grid; }
void Map::setGrid(const decltype(grid)& newGrid) { grid = newGrid; }

void Map::read(std::istream& in) {
    for (int y = 0; y < MAP_HEIGHT; ++y)
        for (int x = 0; x < MAP_WIDTH; ++x)
            in >> grid[y][x];
}

void Map::print(std::ostream& out) const {
    for (const auto& row : grid) {
        for (char cell : row) out << cell << ' ';
        out << '\n';
    }
}

void Map::reset() {
    load(); 
}
