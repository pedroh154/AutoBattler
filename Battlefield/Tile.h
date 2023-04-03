#pragma once
#include "../Characters/Character.h"

struct Tile
{
public:
    Tile(int row, int column);
    
private:
    Character* _currentCharacter = nullptr;

    int _row;

public:
    int GetRowNum() const;
    int GetColumnNum() const;

private:
    int _column;
};
