#include <iostream>
#include <string>
#include <algorithm>
#include "../include/Game.hpp"
#include "../include/GameState.hpp"
#include "../include/Cmd.hpp"
#include "../include/Tools.hpp"
//#include "../include/GameHUD.hpp"

Game::Game() {
    isRunning = true;
    isInitialized = false;
}

Game::~Game() {}

void Game::commandList() {
    SetTerminalColor(T_BrBlue);
    std::cout << "List of cmds ---> ";
    SetTerminalColor(T_BrGreen);
    for(const auto& [key, _] : cmdMap) {
        std::cout << key << ", ";
    }
    std::cout << "\n";
    ResetTerminalColor();
}

void Game::update(std::string ipt) {
    GameState gSt;
    std::transform(input.begin(), input.end(), input.begin(), ::tolower); // To lower input
    auto var = cmdMap.find(input);
    if(var != cmdMap.end()) {
        Cmd cmd = var->second;
        if(!isInitialized) {
            switch(cmd) {
            case Cmd::START:
                isInitialized = true;
                SetTerminalColor(T_BrGreen);
                std::cout << "START\n";
                ResetTerminalColor();
                // TODO: Implement lockin in game state to prevent access of menu cmds
                gSt.Menu();
                break;
            case Cmd::END:
                std::cout << "Ending...\n";
                // TODO: Implement safe program end cycle
                isRunning = false;
                break;
            case Cmd::CREDITS:
                std::cout << "Credits\n";
                break;
            case Cmd::L_CMD: 
                commandList();
                break;
            default:  
                SetTerminalColor(T_Blue);
                std::cout << "Game not initialized. Please use ---> start / go\n";
                ResetTerminalColor();
            }
        } 
        else {
            switch(cmd) {
                case Cmd::END:
                    std::cout << "Ending...\n";
                    // TODO: Implement safe program end cycle
                    isRunning = false;
                    break;
                case Cmd::L_CMD: 
                    commandList();
                    break;
                default: {
                    gSt.process(var);
                    break;
                }
            }
        }
    } 
    else {
        SetTerminalColor(T_Red);
        std::cout << "Unexpected Command! (cmd or help for list of commands) \n"; 
        ResetTerminalColor();
    }

}
 
void Game::render() {

}

void Game::run() {
    
    while (isRunning) {
        SetTerminalColor(T_Yellow);
        std::cout << "Enter your command ---> ";
        ResetTerminalColor();
        std::getline(std::cin, input);
        std::cout << "\n";
        update(input);
        render();
    }
}