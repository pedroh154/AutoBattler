#pragma once
#include <cinttypes>

#include "../Characters/Character.h"

class Player;
class Character;
class Grid;

class BattleField
{
	
public:
	BattleField();
	void Setup();
	void DrawGrid();
	Character* AllocateCharacter(int classIndex, int teamNum);
private:
	
	
	Grid* _grid;
	
	int _currentTurn;

	
	
	int numberOfPossibleTiles;
	

	void StartGame();

	void StartTurn();

	void HandleTurn();

	int GetRandomInt(int min, int max);

	void AlocatePlayers();

	void AlocatePlayerCharacter();

	void AlocateEnemyCharacter();
	
};


