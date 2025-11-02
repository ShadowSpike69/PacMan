#include "Ghost.hpp"
#include <cstdlib> 
#include <ctime>   
#include <iostream>

void Ghost::draw() const {
    std::cout << "Drawing ghost " << color << " at (" << x << ", " << y << ")\n";
}
void Ghost::move() {
    
    srand(time(nullptr));
    int dir = rand() % 4;
    switch (dir) {
        case 0: y--; break; 
        case 1: y++; break; 
        case 2: x--; break; 
        case 3: x++; break; 
    }
}
Ghost::Ghost(int x, int y, const std::string& color)
    : x(x), y(y), color(color) {
}
int Ghost::getX() const {
    return x;
}

int Ghost::getY() const {
    return y;
}

void Ghost::resetPosition() {
    x = 5;
    y = 3;
    isScared = false;
}
Ghost::Ghost() : x(0), y(0), isScared(false), color("red") {}

void Ghost::setX(int x) { this->x = x; }
void Ghost::setY(int y) { this->y = y; }
void Ghost::setScared(bool scared) { isScared = scared; }
void Ghost::setColor(const std::string& color) { this->color = color; }

void Ghost::read(std::istream& in) {
    in >> x >> y >> isScared >> color;
}

void Ghost::print(std::ostream& out) const {
    out << "Ghost " << color << " at (" << x << ", " << y << ")"
        << (isScared ? " [scared]" : "");
}
