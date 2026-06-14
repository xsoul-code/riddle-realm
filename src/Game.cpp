#include <iostream>
#include <string>
#include <algorithm>
#include "../include/Game.hpp"
#include "../include/GameState.hpp"
#include "../include/Cmd.hpp"
#include "../include/Tools.hpp"
#include "../include/GameHUD.hpp"

Game::Game() {
    isRunning = true;
    isInitialized = false;
}

Game::~Game() {}

void Game::commandList() {
    {
        Color c(T_BrBlue);
        std::cout << "List of cmds ---> ";
    }
    Screen state = GameState::getState();
    for(const auto& [key, cmd] : cmdMap) {
        auto ctx = cmdCtxMap.at(cmd);
        if(!isInitialized && ctx != CmdCtx::PRE_GAME && ctx != CmdCtx::ALWAYS) continue;
        if(isInitialized && state == Screen::Menu && ctx != CmdCtx::MENU && ctx != CmdCtx::ALWAYS) continue;
        if(isInitialized && state != Screen::Menu && ctx != CmdCtx::IN_GAME && ctx != CmdCtx::ALWAYS) continue;
        Color c(isInitialized ? T_BrYellow : T_BrGreen);
        std::cout << key << ", ";
    }
    std::cout << "\n";
}

void Game::update(std::string ipt) {
    std::transform(ipt.begin(), ipt.end(), ipt.begin(), tolower); // To lower input
    auto var = cmdMap.find(ipt);
    if(var != cmdMap.end()) {
        Cmd cmd = var->second;
        if(!isInitialized) {
            switch(cmd) {
            case Cmd::START:
                isInitialized = true;
                {
                    Color c(T_BrGreen);
                    std::cout << "START\n";
                }
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
            default: {
                Color c(T_Blue);
                std::cout << "Game not initialized. Please use ---> start / go\n";
            }
            }
        } 
        else {
            switch(cmd) {
                case Cmd::END:
                    clearScreen();
                    std::cout << "Exiting...\n";
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
        Color c(T_Red);
        std::cout << "Unexpected Command! (cmd or help for list of commands) \n";
    }

}
 
void Game::render() {

}

void Game::run() {
    
    while (isRunning) {
        {
            Color c(T_Yellow);
            std::cout << "Enter your command ---> ";
        }
        std::getline(std::cin, input);
        std::cout << "\n";
        update(input);
        render();
    }
}