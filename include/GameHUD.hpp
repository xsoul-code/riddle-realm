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
    static std::string clientName;
    static int clientLevel;
    static int clientXP;
    static int clientXPThresh;
    std::map<int, Biomes> biomeMap;
    int biome;
public:
    GameHUD();
    void printGenericInfo();
    void setHeroClass();
    void printBiomeInfo();
    int getLvlThresh();
};