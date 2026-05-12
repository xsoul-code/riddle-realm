#include <iostream>
#include "../include/Tools.hpp"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void SetTerminalColor(int textColor) {
    std::cout << "\033[" << textColor << "m";
}

void ResetTerminalColor() {
    std::cout << "\033[0m";
}

void printASCII(const std::string& filename) {
    std::fstream file(filename);

    if(!file.is_open()) {
        std::cerr << "Error: Cannot open ASCII file " << filename << "\n";
        return;
    }
    std::string line;
    while(std::getline(file, line)) {
        std::cout << line << "\n";
    }
    file.close();
}