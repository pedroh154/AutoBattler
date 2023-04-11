#pragma once
#include <Vector>

#include "Tile.h"

class Grid
{
    friend class Battlefield;
public:
    Grid(int rows, int columns);
    ~Grid();
    
    void Draw();
    std::vector<std::vector<Tile*>> _tiles;
private:
    int _rows;
    int _columns;

    void SetupTiles();
    
    
    
    // prints the matrix that indicates the tiles of the battlefield
    void drawBattlefield(int Lines, int Columns);
public:
    bool IsValidTileCoordinate(int row, int col) const;

   
};



