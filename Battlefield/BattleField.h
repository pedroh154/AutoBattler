#pragma once
#include "Grid.h"
#include "../Characters/Character.h"

struct Tile;
class Player;
class Character;
class Grid;

class BattleField
{
	
public:
	BattleField(int gridRowNum, int gridColNum);
	void DrawGrid();
	std::vector<Tile*> _unnocupiedTiles;

private:
	Grid* _grid;
	

public:
	Grid* GetGrid() const
	{
		return _grid;
	}

	std::vector<std::vector<Tile*>> GetBattlefieldTiles() const
	{
		return _grid->_tiles;
	};
	
	int GetRandomInt(int min, int max);
	int GetRandomRow();
	int GetRandomCol();
	Tile* GetRandomTile(bool mustBeUnoccupied = false);
	
	virtual Character* GetClosestCharacterFrom(Tile* tile, bool ignoreSameTeam = false);
	
};


