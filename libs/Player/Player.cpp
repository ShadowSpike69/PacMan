#include "Player.hpp"
#include <iostream>

Player::Player() : x(0), y(0), lives(3), name("Anonim") {}

Player::Player(int x, int y, int lives, const std::string& name)
    : x(x), y(y), lives(lives), name(name) {
}

Player::Player(const Player& other)
    : x(other.x), y(other.y), lives(other.lives), name(other.name) {
}

Player& Player::operator=(const Player& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        lives = other.lives;
        name = other.name;
    }
    return *this;
}

bool Player::operator==(const Player& other) const {
    return x == other.x && y == other.y && lives == other.lives && name == other.name;
}

bool Player::operator!=(const Player& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Player& p) {
    out << "Player " << p.name << " at (" << p.x << ", " << p.y << ") with " << p.lives << " lives";
    return out;
}

std::istream& operator>>(std::istream& in, Player& p) {
    in >> p.name >> p.x >> p.y >> p.lives;
    return in;
}

void Player::draw() const {
    std::cout << "Drawing player " << name << " at (" << x << ", " << y << ") with " << lives << " lives\n";
}

void Player::move(char direction) {
    switch (direction) {
    case 'w': y--; break;
    case 's': y++; break;
    case 'a': x--; break;
    case 'd': x++; break;
    }
}

int Player::getX() const { return x; }
int Player::getY() const { return y; }
void Player::resetPosition() { x = 0; y = 0; }


void Player::setX(int x) { this->x = x; }
void Player::setY(int y) { this->y = y; }
void Player::setLives(int lives) { this->lives = lives; }
void Player::setName(const std::string& name) { this->name = name; }

void Player::read(std::istream& in) {
    in >> name >> x >> y >> lives;
}

void Player::print(std::ostream& out) const {
    out << "Player " << name << " at (" << x << ", " << y << ") with " << lives << " lives";
}
