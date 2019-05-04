/**
 * \file GameBoard.h
 * \brief GameBoard module for Conway's Game of Life - tracks state of gameboard
 * \author Leon So | macid: sol4
 * \date 2019-04-13
 */
#ifndef A4_GAME_BOARD_H_
#define A4_GAME_BOARD_H_

#include "CellTypes.h"
#include "Cell.h"
#include "CellGrid.h"

class Board
{
  private:
    CellGrid grid;
    CellGrid init_board();
    void setAlive(nat x, nat y);
    void setDead(nat x, nat y);
    void countNeighbours();

  public:
    /**
     * \brief Empty constructor for a board
     */
    Board();

    /**
     * \brief Constructor for a board
     */
    Board(const char *inFile);

    /**
     * \brief Getter - gets cell at x and y coordinate
     * \param x - the x coordinate of the cell
     * \param y - the y coordinate of the cell
     * \return returns a cell
     */
    Cell getCell(nat x, nat y) const;

    /**
     * \brief Getter - gets the next state of the game
     */
    void nextState();

    /**
     * \brief Calls the View() function to output and view game state
     */
    void outputAndView();
};

#endif
