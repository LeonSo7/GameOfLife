/**
 * \file Cell.cpp
 * \author Leon So | macid: sol4
 * \date 2019-04-13
 */

#include "CellTypes.h"
#include "Cell.h"
#include <stdexcept>

Cell::Cell() {}

Cell::Cell(nat n0, nat n1)
{
    if (n0 >= 25 || n1 >= 25) throw std::invalid_argument("Invalid argument");
    this->x = n0;
    this->y = n1;
    this->state = Dead;
    this->adj = 0;
}

nat Cell::getX() const
{
    return x;
}

nat Cell::getY() const
{
    return y;
}

CellState Cell::getState() const
{
    return state;
}

void Cell::setState(CellState s)
{
    this->state = s;
}

void Cell::setAdj(nat a)
{
    this->adj = a;
}

nat Cell::getAdj() const
{
    return adj;
}
