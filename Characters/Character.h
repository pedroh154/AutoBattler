#pragma once

class Character
{
    
public:
    Character(int teamNum);
    ~Character();

protected:
    float Health;
    float BaseDamage;
    float DamageMultiplier;
    int TeamNum;

    

   // bool TakeDamage(float amount);

    //int getIndex(vector<Types::GridBox*> v, int index);

   // void Die();

   // void WalkTo(bool CanWalk);

    //void StartTurn(Grid* battlefield);

    //bool CheckCloseTargets(Grid* battlefield);

   //void Attack(Character* target);
    
};

