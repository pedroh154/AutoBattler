#pragma once

struct Tile;
class Character;

class Utils
{
public:
    static int clamp(int min, int max, int value);
    static double distanceBetween(Tile* from, Tile* to);
};
