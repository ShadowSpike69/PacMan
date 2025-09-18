#pragma once
#include "Map.hpp"
#include "Player.hpp"
#include "Ghost.hpp"
#include <vector>

class GameEngine {
public:
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
