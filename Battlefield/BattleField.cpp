#include "BattleField.h"
#include <iostream>
#include "../Characters/Character.h"
#include "Grid.h"

BattleField::BattleField(int gridRowNum, int gridColNum)
{
    _grid = new Grid(gridRowNum, gridColNum);
}

void BattleField::DrawGrid()
{
    _grid->Draw();
}

int BattleField::GetRandomRow()
{
    srand(time(nullptr));
    return rand() % _grid->_tiles[0].size();
}

int BattleField::GetRandomCol()
{
    srand(time(nullptr));
    return rand() % _grid->_tiles[GetRandomRow()].size();
}

Character* BattleField::GetClosestCharacterFrom(Tile* tile, bool ignoreSameTeam)
{
    return nullptr;
}

int BattleField::GetRandomInt(int min, int max)
{
    int index = GetRandomInt(min, max);
    return index;
}
