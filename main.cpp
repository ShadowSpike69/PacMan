#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "Player.hpp"
#include "Ghost.hpp"
#include "Map.hpp"

int main() {
    std::vector<std::shared_ptr<Player>> players;
    players.push_back(std::make_shared<Player>(1, 2, 3, "PacMan"));
    players.push_back(std::make_shared<Player>(3, 1, 2, "MsPacMan"));

    std::vector<std::shared_ptr<Ghost>> ghosts;
    ghosts.push_back(std::make_shared<Ghost>(5, 6, "Red"));
    ghosts.push_back(std::make_shared<Ghost>(2, 4, "Blue"));

    Map m1;
    m1.draw();

    for (const auto& p : players) p->draw();
    for (const auto& g : ghosts) g->draw();

    std::sort(players.begin(), players.end(), [](const std::shared_ptr<Player>& a, const std::shared_ptr<Player>& b) {
        return a->getX() < b->getX();
    });

    std::cout << "Players sorted by X:\n";
    for (const auto& p : players) p->print(std::cout), std::cout << "\n";

    auto it = std::find_if(players.begin(), players.end(), [](const std::shared_ptr<Player>& p) {
        return p->getX() == 3;
    });
    if (it != players.end()) {
        std::cout << "Player with X=3 found: ";
        (*it)->print(std::cout);
        std::cout << "\n";
    }

 
    auto p3 = std::make_shared<Player>();
    std::cout << "Introdu nume, x, y, lives: ";
    std::cin >> *p3;
    std::cout << "Player introdus: " << *p3 << "\n";
    players.push_back(p3);

    if (*players[0] == *players[1]) {
        std::cout << "Primii doi jucători sunt egali\n";
    } else {
        std::cout << "Primii doi jucători sunt diferiți\n";
    }

    return 0;
}
