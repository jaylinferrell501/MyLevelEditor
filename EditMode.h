#pragma once
#include "Screen.h"
#include "Tile.h"
#include "Selector.h"
class EditMode : public Screen
{
	Tile mLevelGrid[20][82];
	int mLevelSizeX;
	int mLevelSizeY;
	std::string mLevelName;
	std::string mToggleDrawOnOff;
	Selector mSelector;
	Tile mFloor{ '.', "Floor" };
	Tile mWall{ '#', "Wall" };
	Tile mCoin{ '$', "Coin" };
	Tile mExit{ 'x', "Exit" };
	Tile mPlayer{ '@', "Player" };
	Tile mLeftDoor{ '[', "Door" };
	Tile mRightDoor{ ']', "Door" };
	Tile mDoor{ '/', "Door" };
	Tile mBomb{ '*', "Bomb" };
	Tile mBombDisarmer{ '!', "BombDisarmer" };
	Tile mKey{ 'k', "Key" };
	Tile mExitKey{ '%', "ExitKey" };
	// enemy 1, enemy 2,
public:
	EditMode();
	void TopUi() override;
	void View() override;
	void BottomUi() override;

	void SetLevelSizeX(const int x) { mLevelSizeX = x; }
	void SetLevelSizeY(const int y) { mLevelSizeY = y; }
	void SetLevelName(const std::string aLevelName) { mLevelName = aLevelName; }

	int GetLevelSizeX() const { return mLevelSizeX; }
	int GetLevelSizeY() const { return mLevelSizeY; }
	std::string GetLevelName() { return mLevelName; }
	std::string GetToggleDrawOnOff() { return mToggleDrawOnOff; }
	void SetToggleDrawOnOff(std::string state) { mToggleDrawOnOff = state; }
	void LevelConfigurator();

	int SaveLevel();
	void EditLevel();
	void LoadLevel();
	void CreateLevel();

	void UpdateLevelGrid();



	// User is able to decide how big the level is with the max being [20][82].
	// Create a map maker function that creates the view.
	// - Ask User for what size Map the want
	// - Ask User For Name of the level
	// - Generates 2d array with proper Ui
	//

	// ToDo
	// Be able to support  
	
};

