#pragma once
#include "Map.hpp"
#include "Player.hpp"
#include "Ghost.hpp"
#include <vector>
#include "Renderable.hpp"

class GameEngine : public Renderable {
public:
    void draw() const override;
    void start();
    void update();
    void render();
private:
    Map map;
    Player pacman;
    std::vector<Ghost> ghosts;
    int score;
    int lives;
    bool isGameOver();
};
