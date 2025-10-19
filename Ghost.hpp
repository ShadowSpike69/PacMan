#pragma once
#include "Renderable.hpp"
#include <string>

class Ghost : public Renderable {
private:
    int x, y;
    bool isScared;
    std::string color;

public:
    void draw() const override;
    void move();
    int getX() const;
    int getY() const;
    void resetPosition();
    Ghost(int x, int y, const std::string& color);
};
