#include "Menu.h"

#include <cassert>
#include <fstream>  // ifstream, ofstream, fstream
#include <iostream>
#include <string>

Menu::Menu(const std::string& menuFileName)
{
	std::ifstream menuFile(menuFileName, std::ios::in);
	assert(menuFile.is_open());

	std::string word;

    getline(menuFile, word);              // need to #include <string>

    // loop until you hit the end-of-file (EOF) character
    while (!menuFile.eof())   // returns true if and when the end of the file was reached on the previous read attempt
    {
        std::cout << word << '\n';   // print that line
        std::getline(menuFile, word);         // try to grab another
    }
}
