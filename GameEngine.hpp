#pragma once
#include "Map.hpp"
#include "Player.hpp"
#include "Ghost.hpp"
#include <vector>
#include <memory>
#include <iostream>
#include "Renderable.hpp"

class GameEngine : public Renderable {
public:
    GameEngine();

    void draw() const override;
    void update();

    int getScore() const;
    void setScore(int score);
    int getLives() const;
    void setLives(int lives);
    Map& getMap();
    Player& getPacman();
    std::vector<Ghost>& getGhosts();

    void read(std::istream& in);
    void print(std::ostream& out) const;

private:
    Map map;
    Player pacman;
    std::vector<Ghost> ghosts;
    int score;
    int lives;
};

void GameEngine::read(std::istream& in) {
    map.read(in);
    pacman.read(in);
    in >> score >> lives;
    for (auto& ghost : ghosts) {
        ghost.read(in);
    }
}

void GameEngine::print(std::ostream& out) const {
    map.print(out);
    pacman.print(out);
    out << "Score: " << score << ", Lives: " << lives << "\n";
    for (const auto& ghost : ghosts) {
        ghost.print(out);
        out << "\n";
    }
}
