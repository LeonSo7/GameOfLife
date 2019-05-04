/**
 * \file View.h
 * \author Leon So | macid: sol4
 * \date 2019-04-13
 */
#ifndef A4_VIEW_H_
#define A4_VIEW_H_

#include "CellTypes.h"
#include "GameBoard.h"
#include "Cell.h"
#include "CellGrid.h"

/**
 * \brief View module for viewing and outputting the state of the game
 */
class View
{
  public:
    /**
     * \brief View module for viewing game in state
     * \param grid - a grid of cells
     */
    void view(CellGrid grid);

    /**
     * \brief write module for writing the state of the game to an output file
     * \param grid - a grid of cells
     */
    void writeState(CellGrid grid);
};

#endif
