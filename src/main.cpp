#include <iostream>
#include <fstream>
#include "../include/Game.hpp"
#include "../include/GameState.hpp"
#include "../include/Tools.hpp"

void printASCII(const std::string& filename) {
    std::fstream file(filename);

    if(!file.is_open()) {
        std::cerr << "Error: Cannot open ASCII file " << filename << "\n";
        return;
    }
    std::string line;
    while(std::getline(file, line)) {
        std::cout << line << "\n";
    }
    file.close();
}

int main() {
    SetTerminalColor(T_Green);
    printASCII("../misc/mainmenu.txt");
    SetTerminalColor(T_BrGreen);
    std::cout << "Terminal Game v1.0 - Why did I do this to myself? \n"; 
    ResetTerminalColor();
    Game game;
    game.run();
    return 0;
}