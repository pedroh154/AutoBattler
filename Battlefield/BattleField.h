#pragma once
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


private:
	Grid* _grid;
	

public:
	Grid* GetGrid() const
	{
		return _grid;
	}
	
	int GetRandomInt(int min, int max);
	int GetRandomRow();
	int GetRandomCol();

	virtual Character* GetClosestCharacterFrom(Tile* tile, bool ignoreSameTeam = false);
	
};


