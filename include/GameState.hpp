#pragma once 
#include <string>
#include "GameHUD.hpp"

enum class Screen {Menu, NewGame, ItemShop, Adventure, Hero, Biomes};

class GameState { 
private:
    static Screen state;
public:
    static Screen getState() { return state; }
    GameHUD HUD;
    GameState();
    ~GameState() = default;
    void Menu();
    void NewGame();
    void ItemShop();
    void Adventure();
    void Hero();
    void Biomes();
    void displayCurrState();
};