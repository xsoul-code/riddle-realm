#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include "../include/Game.hpp"
#include "../include/GameState.hpp"
#include "../include/Cmd.hpp"
//#include "../include/GameHUD.hpp"

Game::Game() {
    isRunning = true;
}

Game::~Game() {
    
}

void Game::update(std::string ipt) {
    GameState gSt;
    std::transform(input.begin(), input.end(), input.begin(), ::tolower); // To lower input
    auto var = cmdMap.find(input);
    if(var != cmdMap.end()) {
        Cmd cmd = var->second;
        switch(cmd) {
        case Cmd::START:
            std::cout << "START\n";
            gSt.Menu();
            break;
        case Cmd::END:
            std::cout << "Ending...\n";
            isRunning = false;
            break;
        case Cmd::CREDITS:
            std::cout << "Credits\n";
            break;
        default:  
            gSt.process(var);
        }
    } 
    else {
        std::cout << "We are empty!\n"; 
    }

}
 
void Game::render() {
    
}

void Game::run() {
    
    while (isRunning) {
        std::cout << "Enter your command ---> ";
        std::getline(std::cin, input);
        std::cout << "\n";
        update(input);
        render();
    }
}