#include "GameEngine.hpp"
#include "InputHandler.hpp"
#include <iostream>

    bool isWall(int x, int y) const;
    bool isPellet(int x, int y) const;
    void eatPellet(int x, int y);
void GameEngine::draw() const {
    std::cout << "Drawing game engine state...\n";
}
void GameEngine::update() {
    InputHandler input;
    char direction = input.getInput();

    int newX = pacman.getX();
    int newY = pacman.getY();

    switch (direction) {
        case 'w': newY--; break;
        case 's': newY++; break;
        case 'a': newX--; break;
        case 'd': newX++; break;
        default: std::cout << "Direcție invalidă!\n"; return;
    }

    if (!map.isWall(newX, newY)) {
        pacman.move(direction);
        if (map.isPellet(newX, newY)) {
            map.eatPellet(newX, newY);
            score += 10;
        }
    } else {
        std::cout << "Ai lovit un perete!\n";
    }
}
