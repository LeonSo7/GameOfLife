/**
 * \file Cell.h
 * \author Leon So | macid: sol4
 * \date 2019-04-13
 */
#ifndef A4_CELL_H_
#define A4_CELL_H_

#include "CellTypes.h"
/**
 * \brief Cell abstract data type
 */
class Cell
{
  private:
    CellState state;
    nat x;
    nat y;
    nat adj;

  public:
    /**
    * \brief Empty constructor for a cell
    */
    Cell();

    /**
    * \brief Empty constructor for a cell
    * \param n0 - the x coordinate of the cell
    * \param n1 - the y coordinate of the cell
    */
    Cell(nat n0, nat n1);

    /**
    * \brief Gets the x coordinate for a cell
    */
    nat getX() const;

    /**
    * \brief Gets the y coordinate for a cell
    */
    nat getY() const;

    /**
    * \brief Sets the state for a cell
    * \param s - the state to be set for the cell
    */
    void setState(CellState s);

    /**
    * \brief Gets the state for a cell
    */
    CellState getState() const;

    /**
    * \brief Gets the number of adjacent cells for a cell
    */
    nat getAdj() const;

    /**
    * \brief Sets the number of adjacent cells for a cell
    * \param n - the number of neighbours/adjacents for the cell
    */
    void setAdj(nat n);
};

#endif
