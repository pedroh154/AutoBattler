#include "Grid.h"

#include <iostream>

#include "Tile.h"

Grid::Grid(int rows, int columns)
{
    _rows = rows;
    _columns = columns;

    SetupTiles();
}

void Grid::SetupTiles()
{
    for (int i = 0; i < _rows; i++)
    {
        std::vector<Tile*> row;
        _tiles.push_back(row);
        
        for (int j = 0; j < _columns; j++)
        {
            Tile* newBox = new Tile(i, j);
            _tiles[i].push_back(newBox);
        }
    }
}

Grid::~Grid() 
{

}

void Grid::Draw()
{
    for (int row = 0; row < _tiles.size(); row++)
    {
        //coordinates
        std::cout << std::endl;
        std::cout << row + 1;

        //actual battlefield
        for(int col = 0; col < _tiles[row].size(); col++)
        {
            std::cout << "[ ]" << std::endl;
        }
    }

    //coordinates
    for(int col = 1; col < _columns + 1; col++)
    {
        std::cout << col << " " << std::endl;
    }
}

void Grid::drawBattlefield(int Lines, int Columns)
{
    // for (int i = 0; i < Lines; i++)
    // {
    //     for (int j = 0; j < Columns; j++)
    //     {
    //         Types::GridBox* currentgrid = new Types::GridBox();
    //         if (currentgrid->ocupied)
    //         {
    //             //if()
    //             printf("[X]\t");
    //         }
    //         else
    //         {
    //             printf("[ ]\t");
    //         }
    //     }
    //     printf("\n");
    // }
    // printf("\n");
}
