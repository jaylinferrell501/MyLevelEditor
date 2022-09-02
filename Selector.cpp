#include "Selector.h"

#include <conio.h>

#include "Tile.h"

Selector::Selector()
	:mSelectorIcon('#')
	,mSelectorType("Wall")
	, mSelectorPositionX(0)
	, mSelectorPositionY(0)
	,mSelectorLastPositionX(0)
	,mSelectorLastPositionY(0)
	, mToggleDraw(false)
{
}

 void Selector::SelectorInput(char movementInput)
{
	
	switch (movementInput)
	{
	case 't':
		SetSelectorLastPositionY(GetSelectorPositionY());
		SetSelectorLastPositionX(GetSelectorPositionX());
		if (mToggleDraw == false)
		{
			mToggleDraw = true;
		}
		else
		{
			mToggleDraw = false;
		}
		break;
	case 'd':
		SetSelectorPositionX(GetSelectorPositionX() + 1);
		SetSelectorLastPositionX(GetSelectorPositionX() - 1);
		SetSelectorLastPositionY(GetSelectorPositionY());
		break;
	case 'a':
		SetSelectorPositionX(GetSelectorPositionX() - 1);
		SetSelectorLastPositionX(GetSelectorPositionX() + 1);
		SetSelectorLastPositionY(GetSelectorPositionY());
		break;
	case 'w':
		SetSelectorPositionY(GetSelectorPositionY() - 1);
		SetSelectorLastPositionY(GetSelectorPositionY() + 1);
		SetSelectorLastPositionX(GetSelectorPositionX());
		break;
	case 's':
		SetSelectorPositionY(GetSelectorPositionY() + 1);
		SetSelectorLastPositionY(GetSelectorPositionY() - 1);
		SetSelectorLastPositionX(GetSelectorPositionX());
		break;
	case 'e':
		SetSelectorIcon('e');
		SetSelectorType("Floor");
		SetSelectorLastPositionY(GetSelectorPositionY());
		SetSelectorLastPositionX(GetSelectorPositionX());
		break;
	case '#':
		SetSelectorIcon('#');
		SetSelectorType("Wall");
		SetSelectorLastPositionY(GetSelectorPositionY());
		SetSelectorLastPositionX(GetSelectorPositionX());
		break;
	case '[':
		SetSelectorIcon('[');
		SetSelectorType("Door");
		SetSelectorLastPositionY(GetSelectorPositionY());
		SetSelectorLastPositionX(GetSelectorPositionX());
		break;
	case ']':
		SetSelectorIcon(']');
		SetSelectorType("Door");
		SetSelectorLastPositionY(GetSelectorPositionY());
		SetSelectorLastPositionX(GetSelectorPositionX());
		break;
	case '/':
		SetSelectorIcon('/');
		SetSelectorType("Door");
		SetSelectorLastPositionY(GetSelectorPositionY());
		SetSelectorLastPositionX(GetSelectorPositionX());
		break;
	case '*':
		SetSelectorIcon('*');
		SetSelectorType("Bomb");
		SetSelectorLastPositionY(GetSelectorPositionY());
		SetSelectorLastPositionX(GetSelectorPositionX());
		break;
	case 'x':
		SetSelectorIcon('x');
		SetSelectorType("Exit");
		SetSelectorLastPositionY(GetSelectorPositionY());
		SetSelectorLastPositionX(GetSelectorPositionX());
		break;
	case '@':
		SetSelectorIcon('@');
		SetSelectorType("Player");
		SetSelectorLastPositionY(GetSelectorPositionY());
		SetSelectorLastPositionX(GetSelectorPositionX());
		break;
	case '!':
		SetSelectorIcon('!');
		SetSelectorType("BombDisarmer");
		SetSelectorLastPositionY(GetSelectorPositionY());
		SetSelectorLastPositionX(GetSelectorPositionX());
		break;
	case '$':
		SetSelectorIcon('$');
		SetSelectorType("Coin");
		SetSelectorLastPositionY(GetSelectorPositionY());
		SetSelectorLastPositionX(GetSelectorPositionX());
		break;
	case '%':
		SetSelectorIcon('%');
		SetSelectorType("ExitKey");
		SetSelectorLastPositionY(GetSelectorPositionY());
		SetSelectorLastPositionX(GetSelectorPositionX());
		break;
	case 'k':
		SetSelectorIcon('k');
		SetSelectorType("Key");
		SetSelectorLastPositionY(GetSelectorPositionY());
		SetSelectorLastPositionX(GetSelectorPositionX());
		break;
	}
}

void Selector::SelectorUpdate(Tile levelGrid[20][82]) const
{
	if (!mToggleDraw)
	{
		if (mSelectorPositionY == mSelectorLastPositionY && mSelectorPositionX == mSelectorLastPositionX)
		{
			levelGrid[mSelectorPositionY][mSelectorPositionX].SetTileSymbol(GetSelectorIcon());
		}
		else
		{
			if (levelGrid[mSelectorPositionY][mSelectorPositionX].GetTileSymbol() == mSelectorIcon)
			{
				Tile NewTile = FixTile(levelGrid);
				levelGrid[mSelectorLastPositionY][mSelectorLastPositionX].SetTileSymbol(NewTile.GetTileSymbol());
				levelGrid[mSelectorLastPositionY][mSelectorLastPositionX].SetTileType(NewTile.GetTileType());
			}
		}
	}
	else
	{
		if (mSelectorPositionY == mSelectorLastPositionY && mSelectorPositionX == mSelectorLastPositionX)
		{

			if (mSelectorIcon == 'e')
			{
				int i = 0;
			}
			else
			{
				levelGrid[mSelectorPositionY][mSelectorPositionX].SetTileSymbol(mSelectorIcon);
				levelGrid[mSelectorPositionY][mSelectorPositionX].SetTileType(mSelectorType);
			}
		}
		else
		{
			if (mSelectorIcon == 'e')
			{
				levelGrid[mSelectorLastPositionY][mSelectorLastPositionX].SetTileSymbol('.');
				levelGrid[mSelectorLastPositionY][mSelectorLastPositionX].SetTileType("Floor");
			}
			else
			{
				levelGrid[mSelectorPositionY][mSelectorPositionX].SetTileSymbol(mSelectorIcon);
				levelGrid[mSelectorPositionY][mSelectorPositionX].SetTileType(mSelectorType);
			}
		}
	}
}

Tile Selector::FixTile(Tile levelGrid[20][82]) const
{
	if (levelGrid[mSelectorLastPositionY][mSelectorLastPositionX].GetTileType() == "Floor")
	{
		return Tile{ '.', "Floor" };
	}
	else if (levelGrid[mSelectorLastPositionY][mSelectorLastPositionX].GetTileType() == "Wall")
	{
		return Tile{ '#', "Wall" };
	}
	else if (levelGrid[mSelectorLastPositionY][mSelectorLastPositionX].GetTileType() == "Door")
	{
		return Tile{ '[', "Door" };
	}
	else if (levelGrid[mSelectorLastPositionY][mSelectorLastPositionX].GetTileType() == "Door")
	{
		return Tile{ ']', "Door" };
	}
	else if (levelGrid[mSelectorLastPositionY][mSelectorLastPositionX].GetTileType() == "Door")
	{
		return Tile{ '/', "Door" };
	}
	else if (levelGrid[mSelectorLastPositionY][mSelectorLastPositionX].GetTileType() == "Bomb")
	{
		return Tile{ '*', "Bomb" };
	}
	else if (levelGrid[mSelectorLastPositionY][mSelectorLastPositionX].GetTileType() == "Exit")
	{
		return Tile{ 'x', "Exit" };
	}
	else if (levelGrid[mSelectorLastPositionY][mSelectorLastPositionX].GetTileType() == "Player")
	{
		return Tile{ '@', "Player" };
	}
	else if (levelGrid[mSelectorLastPositionY][mSelectorLastPositionX].GetTileType() == "BombDisarmer")
	{
		return Tile{ '!', "BombDisarmer" };
	}
	else if (levelGrid[mSelectorLastPositionY][mSelectorLastPositionX].GetTileType() == "Coin")
	{
		return Tile{ '$', "Coin" };
	}
	else if (levelGrid[mSelectorLastPositionY][mSelectorLastPositionX].GetTileType() == "ExitKey")
	{
		return Tile{ '%', "ExitKey" };
	}
	else if (levelGrid[mSelectorLastPositionY][mSelectorLastPositionX].GetTileType() == "Key")
	{
		return Tile{ 'k', "Key" };
	}

	return Tile{ '.', "Floor" };
}
