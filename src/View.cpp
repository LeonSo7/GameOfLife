/**
 * \file View.cpp
 * \author Leon So | macid: sol4
 * \date 2019-04-13
 */

#include "CellTypes.h"
#include "Cell.h"
#include "CellGrid.h"
#include "View.h"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <functional>
#include <fstream>
#include <string>
#include <sstream>

void View::view(CellGrid grid){
    std::cout << "Conway's Game of Life by Leon So" << std::endl;
    std::cout << "25 x 25 board" << std::endl;
    std::cout << "Legend: '#' = Alive, ' ' = Dead" << std::endl;
    for (int x = 0; x < 25; x++)
    {
        for (int y = 0; y < 25; y++)
        {
            //If cell in grid is alive, put #
            if (grid[x][y].getState() == Alive){
                std::cout << "[" << "#" << "]";
            } else {
                std::cout << "[" << " " << "]";
            }
        }
        std::cout << std::endl;
    }

}

void View::writeState(CellGrid grid){
    std::ofstream outFile;
    outFile.open ("output.txt");
    
    nat lineCount = 0;
    for (int x = 0; x < 25; x++)
    {
        for (int y = 0; y < 25; y++)
        {
            //If cell in grid is alive, add coordinates to output file
            if (grid[x][y].getState() == Alive){
                if (lineCount != 0){
                    outFile << std::endl;
                }

                outFile << x << "," << y;
                lineCount +=1;
            }
        }
    }

    outFile.close();
}