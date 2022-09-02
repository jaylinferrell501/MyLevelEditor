#include "EditMode.h"

#include <cassert>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>

#include "LevelEditorGame.h"

EditMode::EditMode()
	:mLevelSizeX(82)
	,mLevelSizeY(19)
	,mToggleDrawOnOff("OFF")
{
    LevelConfigurator();
}

void EditMode::TopUi()
{
    std::ifstream EmTUI("EditModeTopUi.txt", std::ios::in);
    assert(EmTUI.is_open());
    std::string word;
    getline(EmTUI, word);            
    while (!EmTUI.eof())
    {
        std::cout << word << '\n';
        std::getline(EmTUI, word);
    }
}

void EditMode::View()
{
    for (int i = 0; i < GetLevelSizeY(); i++)
    {
        for (int j = 0; j < GetLevelSizeX(); j++)
        {
            std::cout << mLevelGrid[i][j].GetTileSymbol();
        }
        std::cout << "\n";
    }
}

void EditMode::BottomUi()
{
    std::cout << "|                                                                                |\n";
    std::cout << "|" << " ToggleDraw[t]: " << GetToggleDrawOnOff() << "                                                               |\n";
	std::cout << "|                                                                                |\n";
	std::cout << "|" << " My Level - " << GetLevelName() << " ""                           " << "                   Save q / Exit o""       |\n";
	std::cout << "|________________________________________________________________________________|\n";
}

void EditMode::LevelConfigurator()
{
    std::cout << "Make New Level? [n] \n";
    std::cout << "Load Current Level? [c] \n";
    char Answer = _getch();
    if (Answer ==  'n')
    {
        system("CLS");
        CreateLevel();
    }
    else if (Answer == 'c')
    {
        system("CLS");
        LoadLevel();
    }
    
}

int EditMode::SaveLevel()
{
    bool isPlayer = false;
    bool isExit = false;
    std::string preSavedFile;
    for (int i = 0; i < GetLevelSizeY(); i++)
    {
        for (int j = 0; j < GetLevelSizeX(); j++)
        {
            if (i == mSelector.GetSelectorPositionY() && j == mSelector.GetSelectorPositionX())
            {
                preSavedFile += mSelector.FixTile(mLevelGrid).GetTileSymbol();
            }
            else
            {
                preSavedFile += mLevelGrid[i][j].GetTileSymbol();
            }
            
            if (mLevelGrid[i][j].GetTileSymbol() == '@')
            {
                isPlayer = true;
            }
            else if (mLevelGrid[i][j].GetTileSymbol() == 'x')
            {
                isExit = true;
            }
        }
        preSavedFile += "\n";
    }
	system("CLS");
    if (!isPlayer || !isExit)
    {
        return 2;
    }
	std::cout << "Are you sure you want to save your level (y/n)\n";
	const char answer = _getch();

	system("CLS");
	if (answer == 'y')
	{
		system("CLS");
		std::ofstream levelFileWriter(GetLevelName(), std::ios::out);
		assert(levelFileWriter.is_open());

		levelFileWriter << preSavedFile;
		std::cout << "You saved your level\n";
		levelFileWriter.close();
        return 1;
	}
    return 3;

}

void EditMode::EditLevel()
{
    char input = _getch();
    int isSaved;
    while (input != 'q' || isSaved != 1)
    {
        mSelector.SelectorInput(input);
        UpdateLevelGrid();
        mSelector.SelectorUpdate(mLevelGrid);
        system("CLS");
        TopUi();
        View();
        if (input == 't')
        {
            if (mSelector.is_ToggleDraw())
            {
                SetToggleDrawOnOff("ON");
            }
            else
            {
                SetToggleDrawOnOff("OFF");
            }
        }
        BottomUi();
        input = _getch();

        if (input == 'q')
        {
            isSaved = SaveLevel();
            if (isSaved == 1)
            {
                LevelEditorGame::MenuScreen();
                break;
            }
            else if (isSaved == 2)
            {
                std::cout << "YOU NEED 1 PLAYER[@] AND 1 EXIT[x]\n";
                std::cout << "Click any key to go back\n";
                _getch();
            }
        }
        if (input == 'o')
        {
            std::cout << "Are you sure you want to leave without saving (y/n)\n";
            char answer = _getch();
            if (answer == 'y')
            {
                system("CLS");
                LevelEditorGame::MenuScreen();
                break;
            }
        }
    }
}

void EditMode::LoadLevel()
{
    std::string aLevel;
    std::cout << "What Level DO you want to edit\n";
    std::cin >> aLevel;
    SetLevelName(aLevel);
    TopUi();
    
    std::ifstream levelFile(aLevel, std::ios::in);
    assert(levelFile.is_open());

    std::string word;

    getline(levelFile, word);              // need to #include <string>

    // loop until you hit the end-of-file (EOF) character
    SetLevelSizeX(word.size());
    int j = 0;
    while (!levelFile.eof())   // returns true if and when the end of the file was reached on the previous read attempt
    {
        for (int i = 0; i < word.size(); i++)
        {
	        if (word[i] == mFloor.GetTileSymbol())
	        {
                mLevelGrid[j][i] = mFloor;
	        }
            else if (word[i] == mPlayer.GetTileSymbol())
            {
                mLevelGrid[j][i] = mPlayer;
            }
            else if (word[i] == mExit.GetTileSymbol())
            {
                mLevelGrid[j][i] = mExit;
            }
            else if (word[i] == mExitKey.GetTileSymbol())
            {
                mLevelGrid[j][i] = mExitKey;
            }
            else if (word[i] == mBomb.GetTileSymbol())
            {
                mLevelGrid[j][i] = mBomb;
            }
            else if (word[i] == mBombDisarmer.GetTileSymbol())
            {
                mLevelGrid[j][i] = mBombDisarmer;
            }
            else if (word[i] == mCoin.GetTileSymbol())
            {
                mLevelGrid[j][i] = mCoin;
            }
            else if (word[i] == mDoor.GetTileSymbol())
            {
                mLevelGrid[j][i] = mDoor;
            }
            else if (word[i] == mLeftDoor.GetTileSymbol())
            {
                mLevelGrid[j][i] = mLeftDoor;
            }
            else if (word[i] == mRightDoor.GetTileSymbol())
            {
                mLevelGrid[j][i] = mRightDoor;
            }
            else if (word[i] == mKey.GetTileSymbol())
            {
                mLevelGrid[j][i] = mKey;
            }
            else if (word[i] == mWall.GetTileSymbol())
            {
                mLevelGrid[j][i] = mWall;
            }
        }
        j++;
        std::getline(levelFile, word);         // try to grab another
    }
    SetLevelSizeY(j);
    View();
    BottomUi();
    EditLevel();

}


void EditMode::CreateLevel()
{
    int SizeX = 0;
    int SizeY = 0;
    std::string levelName;

    std::cout << "Level Size X MAX 82 \n";
    std::cout << "Level Size Y MAX 19 \n";
    std::cout << "\n";
    std::cout << "Level Size X: \n";
    std::cin >> SizeX;
    std::cout << "Level Size Y: \n";
    std::cin >> SizeY;
    std::cout << "Level Name: \n";
    std::cin >> levelName;
    SetLevelSizeX(SizeX);
    SetLevelSizeY(SizeY);
    SetLevelName(levelName);
    // Make Errors for incorrect input!!!!!!!!
    for (int i = 0; i < GetLevelSizeY(); i++)
    {
        for (int j = 0; j < GetLevelSizeX(); j++)
        {
            mLevelGrid[mSelector.GetSelectorPositionY()][mSelector.GetSelectorPositionX()].SetTileSymbol(mSelector.GetSelectorIcon());
            mLevelGrid[i][j] = mFloor;
        }
    }
    system("CLS");
    TopUi();
    View();
    BottomUi();
    EditLevel();
}

void EditMode::UpdateLevelGrid()
{
	mLevelGrid[mSelector.GetSelectorPositionY()][mSelector.GetSelectorPositionX()].SetTileSymbol(mSelector.GetSelectorIcon());
}
