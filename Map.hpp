#pragma once
#include <vector>
#include "Renderable.hpp"

class Map : public Renderable {
public:
    void draw() const override;
    std::vector<std::vector<char>> grid;
    int width, height;
    void load();
    bool isWall(int x, int y)const;
    bool isPellet(int x, int y)const;
    void eatPellet(int x, int y);
};
