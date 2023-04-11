#pragma once
#include <string>

class Game;

class Character
{
    friend Game;
    
private:


public:
    Character(int teamNum);
    ~Character();

    virtual std::string GetName() = 0;

protected:
    float Health = 100.0f;
    float BaseDamage = 30.0f;
    float DamageMultiplier = 1.0f;
    int TeamNum = -1;

    

   // bool TakeDamage(float amount);

    //int getIndex(vector<Types::GridBox*> v, int index);

   // void Die();

   // void WalkTo(bool CanWalk);

    //void StartTurn(Grid* battlefield);

    //bool CheckCloseTargets(Grid* battlefield);

   //void Attack(Character* target);
    
};

