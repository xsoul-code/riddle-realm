#include <iostream>
#include <string>
#include <algorithm>
#include "../include/GameState.hpp"
#include "../include/Cmd.hpp"

GameState::GameState() {
}

void GameState::process(std::map<std::string, Cmd>::const_iterator input) {
    switch(input->second) {
        case Cmd::MENU: {
            Menu();
            break;
        }
        case Cmd::NEWGAME: {
            NewGame();
            break;
        }
        case Cmd::ITEMSHOP: {
            ItemShop();
            break;
        }
        case Cmd::HERO: {
            Hero();
            break;
        }
        case Cmd::ADVENTURE: {
            Adventure();
            break;
        }
        case Cmd::BIOMES: {
            Biomes();
            break;
        }
        default: {
            throw std::runtime_error("Unexpected Error!\n");
            break;
        }
    }
}

void GameState::Menu() {
    state = 1;
    std::cout << "Menu!\n"; 
}

void GameState::NewGame() {
    state = 2;
    std::cout << "NewGame!\n";
}

void GameState::ItemShop() {
    state = 3;
    std::cout << "ItemShop!\n";
}

void GameState::Adventure() {
    state = 4;
    std::cout << "Adventure!\n";
}

void GameState::Hero() {
    state = 5;
    std::cout << "Hero!\n"; 
}

void GameState::Biomes() {
    state = 6;
    std::cout << "Biomes!\n";
}