#include <iostream>
#include "../include/Tools.hpp"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void SetTerminalColor(int textColor) {
    std::cout << "\033[" << textColor << "m";
}

void ResetTerminalColor() {
    std::cout << "\033[0m";
}