#pragma once
#include <string>

class GameHUD {
private:
    static std::string clientName;
    static int clientLevel;
    static int clientXP;
    static int clientXPThresh;
    int biome;
public:
    GameHUD();
    void printGenericInfo();
    void setHeroClass();
    void printBiomeInfo();
    int getLvlThresh();
};