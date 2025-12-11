#include "GameEngine.hpp"
#include "InputHandler.hpp"
#include <iostream>


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
GameEngine::GameEngine() : score(0), lives(3) {}

int GameEngine::getScore() const { return score; }
void GameEngine::setScore(int s) { score = s; }
int GameEngine::getLives() const { return lives; }
void GameEngine::setLives(int l) { lives = l; }
Map& GameEngine::getMap() { return map; }
Player& GameEngine::getPacman() { return pacman; }
std::vector<Ghost>& GameEngine::getGhosts() { return ghosts; }

void GameEngine::read(std::istream& in) {
    map.read(in);
    pacman.read(in);
    in >> score >> lives;
}

void GameEngine::print(std::ostream& out) const {
    map.print(out);
    pacman.print(out);
    out << "Score: " << score << ", Lives: " << lives << "\n";
}

