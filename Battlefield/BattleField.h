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
	void InsertCharacterInBattlefield(Character* character, Tile* tile);

private:
	Grid* _grid;
	Character* AllocateCharacter(int classIndex, int teamNum);

public:
	Grid* GetGrid() const
	{
		return _grid;
	}
	
	int GetRandomInt(int min, int max);
	int GetRandomRow();
	int GetRandomCol();
	
};


