#pragma once

struct Tile;
class Character;

class Utils
{
public:
    template<typename T>
    static T Clamp(T min, T max, T value)
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
    
    static double distanceBetween(Tile* from, Tile* to);
};
