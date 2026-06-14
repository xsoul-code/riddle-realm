#include <iostream>
#include <string>
#include <algorithm>
#include "../include/GameState.hpp"
#include "../include/Cmd.hpp"
#include "../include/Tools.hpp"
#include "../include/GameHUD.hpp"

Screen GameState::state = Screen::Menu;

GameState::GameState() {
    GameState::state = Screen::Menu;
}

void GameState::process(std::map<std::string, Cmd>::const_iterator input) {
    if(state == Screen::Menu) {
        switch(input->second) {
            case Cmd::MENU: {
                std::cout << "You are in Menu already!\n";
                break;
            }
            case Cmd::NEWGAME: {
                std::cout << "You've chosen to create a new adventure.\n";
                NewGame();
                break;
            }
            case Cmd::L_CMD: {
                std::cout << "List of Menu cmds: ";
                for(const auto& [cmd, _] : cmdMap) {
                    SetTerminalColor(T_BrYellow);
                    std::cout << cmd << ", " << std::endl;
                }
                break;
            }
            case Cmd::LOAD: {
                std::cout << "LOAD GAME - Coming soon!\n";
                break;
            }
            case Cmd::WHERE: {
                displayCurrState();
                break;
            }
            default: {
                SetTerminalColor(T_Green);
                std::cout << input->first;
                SetTerminalColor(T_Magenta);
                std::cout << " cannot be used here. You must be in-game.\n";
                ResetTerminalColor();
                break;
            }
        }
    }
    else {
        switch(input->second) {
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
            case Cmd::WHERE: {
                displayCurrState();
                break;
            }
            default: {
                SetTerminalColor(T_Green);
                std::cout << input->first;
                SetTerminalColor(T_Magenta);
                std::cout << " is not an in-game command.\n";
                ResetTerminalColor();
                break;
            }
        }
    }
}

void GameState::displayCurrState() {
    SetTerminalColor(T_BrCyan);
    switch(state) {
        case Screen::Menu: {
            std::cout << "You are in main menu.\n"; 
            break;
        }
        case Screen::NewGame: {
            std::cout << "You are in new game creation.\n";
            break;
        }
        case Screen::ItemShop: {
            std::cout << "You are in your local ItemShop.\n";
            break;
        }
        case Screen::Adventure: {
            std::cout << "You are pursuing an adventure.\n";
            break;
        }
        case Screen::Hero: {
            std::cout << "You are viewing your hero.\n";
            break;
        }
        case Screen::Biomes: {
            std::cout << "You are admiring biomes.\n";
            break;
        }
        default: {
            std::cout << "You are in uncharted territory\n";
            break;
        }
    }
}

void GameState::Menu() {
    clearScreen();
    state = Screen::Menu;
    SetTerminalColor(T_BrWhite);
    std::cout << "Welcome to RiddleRealm!\n"; 
    std::cout << "\nA game which aims to combine idle grind with a sprinkle of mind puzzles. ";
    std::cout << "This is an open source project created solely for fun of programming and problem-solving.\n";
    std::cout << "Start a new game or load up from save (comming soon!) to begin your adventure!\n";
    ResetTerminalColor();
}

void GameState::NewGame() {
    state = Screen::NewGame;
    std::cout << "NewGame!\n";
}

void GameState::ItemShop() {
    state = Screen::ItemShop;
    std::cout << "ItemShop!\n";
}

void GameState::Adventure() {
    state = Screen::Adventure;
    std::cout << "Adventure!\n";
}

void GameState::Hero() {
    state = Screen::Hero;
    std::cout << "Hero!\n"; 
    HUD.printGenericInfo();
}

void GameState::Biomes() {
    state = Screen::Biomes;
    std::cout << "Biomes!\n";
}