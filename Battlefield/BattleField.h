#pragma once
#include "../Characters/Character.h"

class Player;
class Character;
class Grid;

class BattleField
{
	
public:
	BattleField();
	void CreateCharacter(int teamNum);
	void DrawGrid();

private:
	Character* AllocateCharacter(int classIndex, int teamNum);
	
	Grid* _grid;
	
	int _currentTurn;

	void Setup();
	
	int numberOfPossibleTiles;
	

	void StartGame();

	void StartTurn();

	void HandleTurn();

	int GetRandomInt(int min, int max);

	void AlocatePlayers();

	void AlocatePlayerCharacter();

	void AlocateEnemyCharacter();
	
};


