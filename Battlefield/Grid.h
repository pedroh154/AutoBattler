#pragma once
#include <Vector>

#include "Tile.h"

typedef std::vector<std::vector<Tile*>> GridTiles;

class Grid
{
    friend class Battlefield;
public:
    Grid(int rows, int columns);
    ~Grid();
    
    void Draw();

    
    GridTiles _tiles;
private:
    int _rows;
    int _columns;

    void SetupTiles();
    
    
    
    // prints the matrix that indicates the tiles of the battlefield
    void drawBattlefield(int Lines, int Columns);
public:
    bool IsValidTileCoordinate(int row, int col) const;

   
};



