#include <iostream>
#include "Player.hpp"
#include "Ghost.hpp"
#include "Map.hpp"

int main() {
    Player p1(1, 2, 3, "PacMan");
    Ghost g1(5, 6, "Red");
    Map m1;

    p1.draw();
    g1.draw();
    m1.draw();

    Player p2 = p1;
    std::cout << "Player copiat: " << p2 << "\n";

    Player p3;
    std::cout << "Introdu nume, x, y, lives: ";
    std::cin >> p3;
    std::cout << "Player introdus: " << p3 << "\n";

    if (p1 == p2) {
        std::cout << "p1 și p2 sunt egali\n";
    }
    else {
        std::cout << "p1 și p2 sunt diferiți\n";
    }

    return 0;
}
