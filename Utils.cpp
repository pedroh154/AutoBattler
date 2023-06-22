#include "Utils.h"
#include "Battlefield/Tile.h"

int Utils::clamp(int min, int max, int value)
{
    if(value > max)
    {
        return max;
    }
    
    if(value < min)
    {
        return min;
    }

    return value;
}

double Utils::distanceBetween(Tile* from, Tile* to)
{
    double distance = 0.0f;

    if(from && to)
    {
        int a = from->GetColumnNum() - to->GetColumnNum();
        int b = from->GetRowNum() - to->GetRowNum();

        double power = pow( (double) a, 2 ) + pow( (double) b, 2 );
        distance = sqrt(power);
    }

    return distance;
}
