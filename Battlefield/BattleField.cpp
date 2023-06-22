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

Tile* BattleField::GetRandomTile(bool mustBeUnoccupied)
{
    Tile* tile;
    
    if(!mustBeUnoccupied)
    {
        tile = GetBattlefieldTiles()[GetRandomRow()][GetRandomCol()];
    }
    else
    {
        std::vector<Tile*> randomized;
        
        for(auto row: _grid->_tiles)
        {
            for(auto tile: row)
            {
                if(!tile->GetCurrentCharacter())
                {
                    randomized.push_back(tile);
                }
            }
        }

        tile = randomized[GetRandomInt(0, randomized.size() - 1)];
    }
    
    return tile;
}

Character* BattleField::GetClosestCharacterFrom(Tile* tile, bool ignoreSameTeam)
{
    return nullptr;
}

int BattleField::GetRandomInt(int min, int max)
{
    srand((unsigned) time(NULL));

    int random = min + (rand() % max);
    
    return random;
}
