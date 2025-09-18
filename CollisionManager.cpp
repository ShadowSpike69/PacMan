#include "CollisionManager.hpp"

bool CollisionManager::checkCollision(const Player& p, const Ghost& g) {
    return p.getX() == g.getX() && p.getY() == g.getY();
}
