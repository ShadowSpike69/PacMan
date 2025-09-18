#pragma once
#include "Player.hpp"
#include "Ghost.hpp"

class CollisionManager {
public:
   bool checkCollision(const Player& p,const Ghost& g);
};

