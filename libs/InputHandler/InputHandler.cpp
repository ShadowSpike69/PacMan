#include "InputHandler.hpp"
#include <iostream>

char InputHandler::getInput() {
    char input;
    std::cout << "Direcție (w/a/s/d): ";
    std::cin >> input;
    return input;
}
