#pragma once
#include <string>
#include <map>

enum class Biomes {
    Woods,
    Lands,
    CastleLand
};

enum class HeroClass {
    Warrior,
    Mage,
    Rogue
};

class GameHUD {
private:
    std::string clientName;
    HeroClass clientClass;
    int clientLevel;
    int clientXP;
    int clientXPThresh;
    int biome;
public:
    GameHUD();
    void printGenericInfo();
    void setName(const std::string& name);
    void setHeroClass(HeroClass);
    std::string getName() const;
    std::string className() const;
    void printBiomeInfo();
    int getLvlThresh();
};