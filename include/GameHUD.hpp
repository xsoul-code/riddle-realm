#pragma once
#include <string>
#include <map>

enum class Biomes {
    Woods,
    Lands,
    CastleLand
};

class GameHUD {
private:
    std::string clientName;
    int clientLevel;
    int clientXP;
    int clientXPThresh;
    std::map<int, Biomes> biomeMap;
    int biome;
public:
    GameHUD();
    void printGenericInfo();
    void setHeroClass();
    void printBiomeInfo();
    int getLvlThresh();
};