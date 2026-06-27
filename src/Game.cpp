#include <iostream>
#include <string>
#include <algorithm>
#include "../include/Game.hpp"
#include "../include/GameState.hpp"
#include "../include/Command.hpp"
#include "../include/Tools.hpp"
#include "../include/GameHUD.hpp"

Game::Game() {
    isRunning = true;
    isInitialized = false;
}

Game::~Game() {}

bool Game::isAvailable(CmdCtx ctx) const {
    if (ctx == CmdCtx::Always) return true;
    if (!isInitialized)        return ctx == CmdCtx::PreGame;
    return GameState::getState() == Screen::Menu
         ? ctx == CmdCtx::Menu
         : ctx == CmdCtx::InGame;
}

void Game::update(std::string ipt) {
    std::transform(ipt.begin(), ipt.end(), ipt.begin(),
                   [](unsigned char c){ return std::tolower(c); });  

    const Command* c = findCommand(ipt);
    if (!c) { Color col(T_Red); std::cout << "Unexpected Command! (cmd / help)\n"; return; }

    if (!isAvailable(c->ctx)) {
        Color col(T_Magenta);
        std::cout << ipt << " cannot be used here.\n";
        return;
    }
    c->run(*this);
}

void Game::commandList() {
    {
        Color col(T_BrBlue);
        std::cout << "Available commands:\n";
    }
    for (const auto& c : commandTable()) {
        if (!isAvailable(c.ctx)) continue;
        {
            Color col(T_BrYellow);
            std::cout << "  " << c.names.front();
        }
        if (c.names.size() > 1) {
            Color col(T_BrBlack);
            std::cout << " (";
            for (size_t i = 1; i < c.names.size(); ++i)
                std::cout << c.names[i] << (i + 1 < c.names.size() ? ", " : "");
            std::cout << ")";
        }
        std::cout << " - " << c.help << "\n";
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