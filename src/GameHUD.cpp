#include <iostream>
#include <map>
#include "../include/GameHUD.hpp"
#include "../include/GameState.hpp"


std::map<int, Biomes> biomeMap = {
    {1, Biomes::Woods},
    {2, Biomes::Lands},
    {3, Biomes::CastleLand}
};

std::map<Biomes, std::string> biomeNameMap = {
    {Biomes::Woods, "Woods"},
    {Biomes::Lands, "Lands"},
    {Biomes::CastleLand, "CastleLand"}
};

std::map<HeroClass, std::string> heroClassNameMap = {
    {HeroClass::Warrior, "Warrior"},
    {HeroClass::Mage, "Mage"},
    {HeroClass::Rogue, "Rogue"}
};

GameHUD::GameHUD() {
    GameHUD::clientName = "Not Named Yet";
    GameHUD::clientClass = HeroClass::Warrior;
    GameHUD::clientLevel = 1;
    GameHUD::clientXP = 0;
    GameHUD::clientXPThresh = 1000;
    GameHUD::biome = 1;
}

void GameHUD::setName(const std::string& name) {
    clientName = name;
}

void GameHUD::setHeroClass(HeroClass c) {
    clientClass = c;
}

std::string GameHUD::getName() const {
    return clientName;
}

std::string GameHUD::className() const {
    auto it = heroClassNameMap.find(clientClass);
    return it != heroClassNameMap.end() ? it->second : "Unknown";
}

void GameHUD::printGenericInfo() {
    std::cout << "The name: " << clientName << std::endl;
    std::cout << "Class: " << className() << std::endl;
    std::cout << "Lvl: " << clientLevel << " XP: " << clientXP << "/" << clientXPThresh << std::endl;
    auto biomeFind = biomeMap.find(biome);
    if(biomeFind != biomeMap.end()) {
        auto biomeName = biomeNameMap.find(biomeFind->second);
        std::cout << "You are in biome: " << biomeName->second << std::endl;
    }
    else {
        std::cout << "Please choose your biome destination" << std::endl;
    }
        
}

void GameHUD::printBiomeInfo() {

}
    
int GameHUD::getLvlThresh() {

    return 1000;
}