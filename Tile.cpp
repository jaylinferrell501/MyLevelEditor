#include "Tile.h"

Tile::Tile(char aTileSymbol, std::string aTileType)
	:mTileSymbol(aTileSymbol)
	,mTileType(std::move(aTileType))
{
}
