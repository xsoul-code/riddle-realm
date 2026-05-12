#include <iostream>
#include "../include/Game.hpp"
#include "../include/GameState.hpp"
#include "../include/Tools.hpp"

int main() {
    SetTerminalColor(T_Green);
    printASCII("misc/mainmenu.txt");
    SetTerminalColor(T_BrGreen);
    std::cout << "Terminal Game v0.0.1 Alpha - Why did I do this to myself? \n"; 
    ResetTerminalColor();
    Game game;
    game.run();
    return 0;
}