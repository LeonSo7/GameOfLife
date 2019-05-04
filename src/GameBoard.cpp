/**
 * \file GameBoard.cpp
 * \author Leon So | macid: sol4
 * \date 2019-04-13
 */

#include "CellTypes.h"
#include "Cell.h"
#include "GameBoard.h"
#include "CellGrid.h"
#include "View.h"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <functional>
#include <fstream>
#include <string>
#include <sstream>

Board::Board() {}

Board::Board(const char *inFile)
{
    //Initialize grid
    this->grid = init_board();

    //Set Alive
    std::vector<std::string> aliveCells;

    std::ifstream in;
    in.open(inFile);
    if (!in)
    {
        throw std::invalid_argument("Unable to open file datafile.txt");
        exit(1); //Call system to stop
    }

    std::string strTemp;
    while (std::getline(in, strTemp))
    {
        //Line contains string of length > 0 then save it in vector
        if (strTemp.size() > 0){
            aliveCells.push_back(strTemp);
        }
    }

    for (nat i = 0; i < aliveCells.size(); i++)
    {
        std::vector<std::string> splitCoords;

        std::string cellCoords = aliveCells[i];

        std::stringstream ss(cellCoords);

        std::string token;

        while (getline(ss, token, ','))
        {
            splitCoords.push_back(token);
        }

        //Set cell alive in grid
        setAlive(stoi(splitCoords[0]), stoi(splitCoords[1]));
    }

    in.close();
}

Cell Board::getCell(nat x, nat y) const
{
    if (x >= 25 || y >= 25) throw std::out_of_range("Out of range");
    return this->grid[x][y];
}

void Board::nextState()
{
    countNeighbours();
    for (nat x = 0; x < 25; x++)
    {
        for (nat y = 0; y < 25; y++)
        {
            if (this->grid[x][y].getAdj() <= 1 || this->grid[x][y].getAdj() >= 4)
            {
                this->grid[x][y].setState(Dead);
            }
            else if (this->grid[x][y].getAdj() == 3)
            {
                this->grid[x][y].setState(Alive);
            }
        }
    }
}

void Board::outputAndView()
{
    View v;
    v.view(this->grid);
    v.writeState(this->grid);
}

//Private methods
CellGrid Board::init_board()
{
    //Initialize board of dead cells
    std::vector<Cell> tempRow;
    CellGrid tempGrid;
    for (nat row = 0; row < 25; row++)
    {
        for (nat col = 0; col < 25; col++)
        {
            tempRow.push_back(Cell(row, col));
        }
        tempGrid.push_back(tempRow);
    }
    return tempGrid;
}

void Board::setAlive(nat x, nat y)
{
    this->grid[x][y].setState(Alive);
}

void Board::setDead(nat x, nat y)
{
    this->grid[x][y].setState(Dead);
}

void Board::countNeighbours()
{
    for (int x = 0; x < 25; x++)
    {
        for (int y = 0; y < 25; y++)
        {
            int rowBelow = x + 1;
            int rowAbove = x - 1;
            int colRight = y + 1;
            int colLeft = y - 1;

            nat count = 0;

            //Check top left cell
            if (rowAbove >= 0 && colLeft >= 0)
            {
                if (this->grid[rowAbove][colLeft].getState() == Alive)
                {
                    count += 1;
                }
            }

            //Check top middle cell
            if (rowAbove >= 0)
            {
                if (this->grid[rowAbove][y].getState() == Alive)
                {
                    count += 1;
                }
            }

            //Check top right cell
            if (rowAbove >= 0 && colRight < 25)
            {
                if (this->grid[rowAbove][colRight].getState() == Alive)
                {
                    count += 1;
                }
            }

            //Check left middle cell
            if (colLeft >= 0)
            {
                if (this->grid[x][colLeft].getState() == Alive)
                {
                    count += 1;
                }
            }

            //Check right middle cell
            if (colRight < 25)
            {
                if (this->grid[x][colRight].getState() == Alive)
                {
                    count += 1;
                }
            }

            //Check bottom left cell
            if (rowBelow < 25 && colLeft >= 0)
            {
                if (this->grid[rowBelow][colLeft].getState() == Alive)
                {
                    count += 1;
                }
            }

            //Check bottom middle cell
            if (rowBelow < 25)
            {
                if (this->grid[rowBelow][y].getState() == Alive)
                {
                    count += 1;
                }
            }

            //Check bottom right cell
            if (rowBelow < 25 && colRight < 25)
            {
                if (this->grid[rowBelow][colRight].getState() == Alive)
                {
                    count += 1;
                }
            }

            //Add neighbour count to cell
            this->grid[x][y].setAdj(count);
        }
    }
}
