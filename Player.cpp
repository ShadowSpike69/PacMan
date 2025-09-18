#include "Player.hpp"

void Player::move(char direction) {
    switch (direction) {
        case 'w': y--; break;
        case 's': y++; break;
        case 'a': x--; break;
        case 'd': x++; break;
    }
}

int Player::getX() const {
    return x;
}

int Player::getY() const {
    return y;
}

void Player::resetPosition() {
    x = 1;
    y = 1;
    lives = 3;
}
