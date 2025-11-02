#pragma once
#include <array> 
#include <iostream>
#include "Renderable.hpp"

class Map : public Renderable {
public:
    static constexpr int MAP_WIDTH = 7;
    static constexpr int MAP_HEIGHT = 5;
    std::array<std::array<char, MAP_WIDTH>, MAP_HEIGHT> grid;
    int width, height;

    void draw() const override;
    void load();
    bool isWall(int x, int y) const;
    bool isPellet(int x, int y) const;
    void eatPellet(int x, int y);

    int getWidth() const;
    int getHeight() const;
    void setWidth(int w);
    void setHeight(int h);
    const auto& getGrid() const;
    void setGrid(const decltype(grid)& newGrid);

    void read(std::istream& in);
    void print(std::ostream& out) const;
    void reset();
};
