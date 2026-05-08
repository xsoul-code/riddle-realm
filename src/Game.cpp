#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include "../include/Game.hpp"
//#include "../include/GameState.hpp"
//#include "../include/GameHUD.hpp"

enum class Cmd{
    START,
    END,
    CREDITS,
};

const std::map<std::string, Cmd> cmdMap {
    {"start", Cmd::START},
    {"go", Cmd::START},

    {"end", Cmd::END},

    {"credits", Cmd::CREDITS},
    {"cred", Cmd::CREDITS}
};

Game::Game() {
    isRunning = true;
}

Game::~Game() {}

void Game::update(auto ipt) {
    switch(ipt) {
        case Cmd::START:
            std::cout << "START" << std::endl;
            break;
        case Cmd::END:
            std::cout << "Ending..." << std::endl;
            isRunning = false;
            break;
        case Cmd::CREDITS:
            std::cout << "Credits" << std::endl;
            break;
        default:  // Fallback this should not be executed because of run() if check
            std::cout << "Unknown Command!" << std::endl;
    }
}

void Game::run() {
    while (isRunning) {
        int ap = 0;
        std::cout << "The Game is Running...\n";
        std::getline(std::cin, input);
        std::transform(input.begin(), input.end(), input.begin(), ::tolower); // To lower input
        auto type = cmdMap.find(input);
        if(type != cmdMap.end()) {
            Cmd cmd = type->second;
            update(cmd);
        }
        else {
            std::cout << "Unknown Command!\n";
        }
    }
}