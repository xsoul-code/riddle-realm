#pragma once
#include <iostream>
#include <string>

class Game {
private:
    bool isRunning;
    std::string input;
public:
    Game();
    ~Game();
    void run();
    void update(auto ipt);
    void render();
};
