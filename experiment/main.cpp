/*
 * Use this file for experimenting with your code,
 * testing things that don't work, debugging, etc.
 *
 * You can compile and run this via 'make experiment'
 *
 * This file will not be graded
 */
#include <algorithm>
#include <iostream>
#include <vector>

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

int main()
{
  std::cout << "'make experiment' will run this main" << std::endl;
  Board board = Board("input.txt");
  board.outputAndView();
  board.nextState();
  board.outputAndView();
  board.nextState();
  board.outputAndView();
}
