#pragma once
#include <string>
class Tile;

class Selector
{
	char mSelectorIcon;
	std::string mSelectorType;
	int mSelectorPositionX;
	int mSelectorPositionY;
	int mSelectorLastPositionX;
	int mSelectorLastPositionY;
	bool mToggleDraw;
public:
	Selector();
	char GetSelectorIcon() const { return mSelectorIcon; }
	void SetSelectorIcon(char icon) { mSelectorIcon = icon; }
	int GetSelectorPositionX() { return mSelectorPositionX; }
	int GetSelectorPositionY() { return mSelectorPositionY; }
	std::string GetSelectorType() { return mSelectorType; }
	void SetSelectorType(std::string type) { mSelectorType = type; }
	void SetSelectorPositionX(int x) { mSelectorPositionX = x; }
	void SetSelectorPositionY(int y) { mSelectorPositionY = y; }
	bool is_ToggleDraw() { return mToggleDraw; }
	void SetToggleDraw(bool state) { mToggleDraw = state; }

	void SetSelectorLastPositionX(int x) { mSelectorLastPositionX = x; }
	void SetSelectorLastPositionY(int y) { mSelectorLastPositionY = y; }

	void SelectorInput(char movementInput);
	void SelectorUpdate(Tile levelGrid[20][82]) const;
	Tile FixTile(Tile levelGrid[20][82]) const;
};

