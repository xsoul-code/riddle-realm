#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>

#define T_Black 30
#define T_Red 31
#define T_Green 32
#define T_Yellow 33
#define T_Blue 34
#define T_Magenta 35
#define T_Cyan 36
#define T_White 37
#define T_BrBlack 90
#define T_BrRed 91
#define T_BrGreen 92
#define T_BrYellow 93
#define T_BrBlue 94
#define T_BrMagenta 95
#define T_BrCyan 96
#define T_BrWhite 97

void clearScreen();

void printASCII(const std::string& filename);

void SetTerminalColor(int textColor); 

void ResetTerminalColor(); 