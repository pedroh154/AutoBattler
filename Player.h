#pragma once
#include <string>

class Player
{
public:
    Player(int teamNum);

public:
    bool CpuControlled = false;
    int TeamNum = -1;
    void OnTurnStarted();
    bool IsDefeated();

public:
    std::string GetName();
};
