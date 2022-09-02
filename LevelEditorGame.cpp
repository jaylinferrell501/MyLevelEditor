#include "LevelEditorGame.h"
#include <iostream>
#include "Menu.h"
#include <stdio.h>
#include <conio.h>

#include "DisplayMode.h"
#include "EditMode.h"

void LevelEditorGame::RunGame()
{
	MenuScreen();
}

void LevelEditorGame::MenuScreen()
{
	Menu GameMenu("Menu.txt");

	const char choice = _getch();
	switch (choice)
	{
	case '1':
		system("CLS");
		EditorModeScreen();
		break;
	case '2':
		system("CLS");
		DisplayModeScreen();
		break;
	case '3':
		system("CLS");
		std::cout << "Play Mode Coming soon :D \n";
		break;
	}
}

void LevelEditorGame::EditorModeScreen()
{
	EditMode editMode;
}

void LevelEditorGame::DisplayModeScreen()
{
	DisplayMode displayMode;
}
