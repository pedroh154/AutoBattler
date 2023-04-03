#include "BattleField.h"
#include <iostream>
#include "../Characters/Character.h"
#include "../Characters/Paladin.h"
#include "../Characters/Archer.h"
#include "../Characters/Cleric.h"
#include "../Characters/Warrior.h"
#include "Grid.h"


BattleField::BattleField()
{
    Setup();
}

void BattleField::Setup()
{
    int sizeX = 0;
    int sizeY = 0;

    while (sizeX <= 0 || sizeY <= 0)
    {
        std::cout << "--- Battlefield configuration ---" << std::endl;
        std::cout << "Enter number of rows: " << std::endl;
        std::cin >> sizeX;

        std::cout << "Enter number of columns: " << std::endl;
        std::cin >> sizeY;
    }
   
    _grid = new Grid(sizeX, sizeY);
}

void BattleField::CreateCharacter(int teamNum)
{
    int classToSpawn = -1;
    
    std::cout << "Pick a class for your new character: " << std::endl;
    std::cout << "[1] Paladin, [2] Warrior, [3] Cleric, [4] Archer" << std::endl;
    std::cin >> classToSpawn;

    if(classToSpawn > 0 && classToSpawn <= 4)
    {
        AllocateCharacter(classToSpawn, teamNum);
    }
    else
    {
        CreateCharacter(teamNum);
    }
}

Character* BattleField::AllocateCharacter(int classIndex, int teamNum)
{
    Character* allocatedChar = nullptr;
    
    switch(classIndex)
    {
        case 1:
            allocatedChar = new Paladin(teamNum);
            break;
        case 2:
            allocatedChar = new Warrior(teamNum);
            break;
        case 3:
            allocatedChar = new Cleric(teamNum);
            break;
        case 4:
            allocatedChar = new Archer(teamNum);
            break;
    }

    return allocatedChar;
}


void BattleField::StartGame()
{
    // //populates the character variables and targets
    // EnemyCharacter->target = PlayerCharacter;
    // PlayerCharacter->target = EnemyCharacter;
    // _players->push_back(PlayerCharacter);
    // _players->push_back(EnemyCharacter);
    // AlocatePlayers();
    // StartTurn();

}

void BattleField::StartTurn() {

    // if (_currentTurn == 0)
    // {
    //     //AllPlayers.Sort();  
    // }
    // std::list<Character>::iterator it;
    //
    // for (it = _players->begin(); it != _players->end(); ++it) {
    //     it->StartTurn(_grid);
    // }
    //
    // _currentTurn++;
    // HandleTurn();
}

void BattleField::HandleTurn()
{
    // if (PlayerCharacter->Health == 0)
    // {
    //     return;
    // }
    // else if (EnemyCharacter->Health == 0)
    // {
    //     printf("\n");
    //
    //     // endgame?
    //
    //     printf("\n");
    //
    //     return;
    // }
    // else
    // {
    //     printf("\n");
    //     printf("Click on any key to start the next turn...\n");
    //     printf("\n");
    //
    //     //TODO
    //     //ConsoleKeyInfo key = Console.ReadKey();
    //     StartTurn();
    // }
}

int BattleField::GetRandomInt(int min, int max)
{
    int index = GetRandomInt(min, max);
    return index;
}

void BattleField::AlocatePlayers()
{
    AlocatePlayerCharacter();
}

void BattleField::AlocatePlayerCharacter()
{
    // int random = 0;
    // auto l_front = _grid->grids.begin();
    // advance(l_front, random);
    // Types::GridBox* RandomLocation = &*l_front;
    //
    // if (!RandomLocation->ocupied)
    // {
    //     //Types::GridBox* PlayerCurrentLocation = RandomLocation;
    //     PlayerCurrentLocation = &*l_front;
    //     l_front->ocupied = true;
    //     PlayerCharacter->currentBox = *l_front;
    //     AlocateEnemyCharacter();
    // }
    // else
    // {
    //     AlocatePlayerCharacter();
    // }
}

void BattleField::AlocateEnemyCharacter()
{
    
    // int random = 24;
    // auto l_front = _grid->grids.begin();
    // advance(l_front, random);
    // Types::GridBox* RandomLocation = &*l_front;
    //
    // if (!RandomLocation->ocupied)
    // {
    //     EnemyCurrentLocation = &*l_front;
    //     l_front->ocupied = true;
    //     EnemyCharacter->currentBox = *l_front;
    //     _grid->drawBattlefield(5, 5);
    // }
    // else
    // {
    //     AlocateEnemyCharacter();
    // }


}