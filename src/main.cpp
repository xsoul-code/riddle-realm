#include <iostream>
#include <fstream>
#include "../include/Game.hpp"
#include "../include/GameState.hpp"

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
    printASCII("../misc/mainmenu.txt");
    std::cout << "Terminal Game v1.0 - Why did I do this to myself? \n"; 
    std::cout << "List of cmds ---> ";
    for(const auto& [key, _] : cmdMap) {
        std::cout << key << ", ";
    }
    std::cout << "\n";
    Game game;
    game.run();
    return 0;
}