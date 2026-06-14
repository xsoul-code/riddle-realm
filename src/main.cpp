#include <iostream>
#include "../include/Game.hpp"
#include "../include/GameState.hpp"
#include "../include/Tools.hpp"

int main() {
    clearScreen();
    {
        Color c(T_Green);
        printASCII("misc/mainmenu.txt");
    }
    {
        Color c(T_BrGreen);
        std::cout << "Terminal Game v0.0.1 Alpha - Why did I do this to myself? \n";
    }
    Game game;
    game.run();
    return 0;
}