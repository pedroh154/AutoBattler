#pragma once
#include <Vector>

#include "Tile.h"

class Grid
{
    
public:
    Grid(int rows, int columns);
    ~Grid();
    
    void Draw();
    
private:
    int _rows;
    int _columns;

    void SetupTiles();
    
    std::vector<std::vector<Tile*>> _tiles;
    
    // prints the matrix that indicates the tiles of the battlefield
    void drawBattlefield(int Lines, int Columns);
public:
    bool IsValidTileCoordinate(int row, int col) const;
};



