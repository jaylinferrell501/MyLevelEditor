#include "DisplayMode.h"

#include <cassert>
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>

#include "LevelEditorGame.h"
std::string aLevel;

DisplayMode::DisplayMode()
{
    std::cout << "What level do you want to display?\n";
    std::cin >> aLevel;
    DisplayLevel();
}

void DisplayMode::TopUi()
{
    std::cout << " ________________________________________________________________________________\n";
    std::cout << "|                                                                                |\n";
    std::cout << "|                                                                                |\n";
    std::cout << "|" << "                                 My Level - "   << aLevel <<"                                   |\n";
    std::cout << "|                                                                                |\n";
    std::cout << "|                                                                                |\n";
}

void DisplayMode::View()
{

    std::ifstream levelFile(aLevel, std::ios::in);
    assert(levelFile.is_open());

    std::string word;

    getline(levelFile, word);              // need to #include <string>

    // loop until you hit the end-of-file (EOF) character
    while (!levelFile.eof())   // returns true if and when the end of the file was reached on the previous read attempt
    {
        std::cout << word << '\n';   // print that line
        std::getline(levelFile, word);         // try to grab another
    }

    levelFile.close();
}

void DisplayMode::BottomUi()
{
    std::ifstream DmBUI("DisplayModeBottomUi.txt", std::ios::in);
    assert(DmBUI.is_open());
    std::string word;
    getline(DmBUI, word);
    while (!DmBUI.eof())
    {
        std::cout << word << '\n';
        std::getline(DmBUI, word);
    }
    DmBUI.close();
}

void DisplayMode::DisplayLevel()
{
    system("CLS");
    DisplayMode::TopUi();

    DisplayMode::View();

    DisplayMode::BottomUi();

    char input = _getch();
    if (input == 'b')
    {
        system("CLS");
        LevelEditorGame::MenuScreen();
    }
}
