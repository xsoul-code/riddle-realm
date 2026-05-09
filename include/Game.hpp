#pragma once
#include <iostream>
#include <string>
#include "GameState.hpp"

class Game {
private:
    bool isRunning;
    std::string input;
    bool isInitialized;
public:
    Game();
    ~Game();
    void run();
    void update(std::string ipt);
    void render();
    void commandList();
};
