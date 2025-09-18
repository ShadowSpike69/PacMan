#include "Ghost.hpp"
#include <cstdlib> 
#include <ctime>   

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
