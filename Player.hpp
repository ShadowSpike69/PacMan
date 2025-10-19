#pragma once
#include "Renderable.hpp"
#include <string>
#include <iostream>

class Player : public Renderable {
private:
    int x, y;
    int lives;
    std::string name;

public:
    Player();
    Player(int x, int y, int lives, const std::string& name);
    Player(const Player& other);
    Player& operator=(const Player& other);

    bool operator==(const Player& other) const;
    bool operator!=(const Player& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Player& p);
    friend std::istream& operator>>(std::istream& in, Player& p);

    void draw() const override;
    void move(char direction);
    int getX() const;
    int getY() const;
    void resetPosition();
};
