#include <iostream>
#include <string>
#include <algorithm>
#include "../include/GameState.hpp"
#include "../include/Tools.hpp"
#include "../include/GameHUD.hpp"

Screen GameState::state = Screen::Menu;

GameState::GameState() {
    GameState::state = Screen::Menu;
}

void GameState::displayCurrState() {
    Color c(T_BrCyan);
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
    Color c(T_BrWhite);
    std::cout << "Welcome to RiddleRealm!\n";
    std::cout << "\nA game which aims to combine idle grind with a sprinkle of mind puzzles. ";
    std::cout << "This is an open source project created solely for fun of programming and problem-solving.\n";
    std::cout << "Start a new game or load up from save (comming soon!) to begin your adventure!\n";
}

static HeroClass chooseHeroClass() {
    while (true) {
        {
            Color c(T_Yellow);
            std::cout << "Choose your class - 1) Warrior  2) Mage  3) Rogue ---> ";
        }
        std::string in;
        std::getline(std::cin, in);
        std::transform(in.begin(), in.end(), in.begin(),
                       [](unsigned char ch){ return std::tolower(ch); });
        if (in == "1" || in == "warrior") return HeroClass::Warrior;
        if (in == "2" || in == "mage")    return HeroClass::Mage;
        if (in == "3" || in == "rogue")   return HeroClass::Rogue;
        Color c(T_Red);
        std::cout << "Invalid choice, try again.\n";
    }
}

void GameState::NewGame() {
    state = Screen::NewGame;
    {
        Color c(T_BrWhite);
        std::cout << "Let's create your hero!\n";
    }

    {
        Color c(T_Yellow);
        std::cout << "Enter your hero's name ---> ";
    }
    std::string name;
    std::getline(std::cin, name);
    if (name.empty()) name = "Nameless Hero";
    HUD.setName(name);

    HUD.setHeroClass(chooseHeroClass());

    {
        Color c(T_BrGreen);
        std::cout << "Welcome, " << HUD.getName() << " the " << HUD.className()
                  << "! Your adventure begins.\n\n";
    }

    state = Screen::Hero;
    HUD.printGenericInfo();
}

void GameState::ItemShop() {
    state = Screen::ItemShop;
    std::cout << "ItemShop\n";
}

void GameState::Adventure() {
    state = Screen::Adventure;
    std::cout << "Adventure: \n";
}

void GameState::Hero() {
    state = Screen::Hero;
    std::cout << "Your Hero information: \n"; 
    HUD.printGenericInfo();
}

void GameState::Biomes() {
    state = Screen::Biomes;
    std::cout << "Biomes screen: \n";
}