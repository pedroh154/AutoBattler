#pragma once
#include <string>
#include <Vector>

class Character;

class Player
{
public:
    Player(int teamNum);

public:
    bool CpuControlled = false;
    int TeamNum = -1;
    void OnTurnStarted();
    bool IsDefeated();

protected:
    std::vector<Character*> MyCharacters;

public:
    void AddCharacter(Character* character);
    std::string GetName();
};
