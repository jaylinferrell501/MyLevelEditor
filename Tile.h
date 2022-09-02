#pragma once
#include <string>
#include <utility>

class Tile
{
	char mTileSymbol;
	std::string mTileType;
public:
	Tile() = default;
	Tile(char aTileSymbol, std::string aTileType);
	char GetTileSymbol() { return mTileSymbol; }
	void SetTileSymbol(char aTileSymbol) { mTileSymbol = aTileSymbol; }
	std::string GetTileType() { return mTileType; }
	void SetTileType(std::string aTileType) { mTileType = std::move(aTileType); } //
};

