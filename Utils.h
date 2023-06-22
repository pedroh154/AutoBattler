#pragma once

class Character;
class Tile;

class Utils
{
public:
    static int clamp(int min, int max, int value);
    static double distanceBetween(Tile* from, Tile* to);
};
