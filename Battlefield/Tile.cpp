#include "Tile.h"

Tile::Tile(int row, int column)
{
    _row = row;
    _column = column;
}

int Tile::GetRowNum() const
{
    return _row;
}

int Tile::GetColumnNum() const
{
    return _column;
}

Character* Tile::GetCurrentCharacter()
{
    return _currentCharacter;
}
