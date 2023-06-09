#include "Grid.h"
#include <iostream>
#include "Tile.h"
#include "BattleField.h"

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
        //draw row coordinate
        std::cout << std::endl;
        std::cout << row + 1;

        //draw actual battlefield
        for(int col = 0; col < _tiles[row].size(); col++)
        {
            Character* currChar = _tiles[row][col]->GetCurrentCharacter();
            if(currChar)
            {
                std::cout << "[" << currChar->GetName() << "]";
            }
            else
            {
                std::cout << "[  ]" << " ";
            }
            
        }
    }

    std::cout << std::endl;
    
    //column coordinates
    for(int col = 1; col < _columns + 1; col++)
    {
        std::cout << "  " << col << "  ";
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

bool Grid::IsValidTileCoordinate(int row, int col) const
{
    return (row > 0 && row <= _rows) && (col > 0 && col <= _columns);
}
