#pragma once

class Grid
{
    
public:
    Grid(int rows, int columns);
    ~Grid();

private:
    int _rows;
    int _columns;
    
    // prints the matrix that indicates the tiles of the battlefield
    void drawBattlefield(int Lines, int Columns);
};

