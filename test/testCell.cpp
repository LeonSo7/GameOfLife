/**
 * \file testCell.cpp
 * \author Leon So | macid: sol4
 * \date 2019-04-13
 */
#include "catch.h"
#include "CellTypes.h"
#include "Cell.h"

#include <stdexcept>

TEST_CASE("tests for Cell", "[Cell]")
{

    Cell cell(1, 2);

    SECTION("normal test case for Cell constructor")
    {
        Cell cellNew(1, 3);
        REQUIRE((
            cellNew.getAdj() == 0 &&
            cellNew.getX() == 1 &&
            cellNew.getState() == Dead && cellNew.getY() == 3));
    }

    SECTION("normal test case for getX")
    {
        REQUIRE((cell.getX() == 1));
    }

    SECTION("normal test case for getY")
    {
        REQUIRE((cell.getY() == 2));
    }

    SECTION("normal test case for getY")
    {
        REQUIRE((cell.getY() != 5));
    }

    SECTION("normal test case for getX")
    {
        REQUIRE((cell.getX() != 2));
    }

    SECTION("abnormal test case for Cell constructor")
    {
        REQUIRE_THROWS_AS(Cell(26,26), std::invalid_argument);
    }

    SECTION("abnormal test case for Cell constructor")
    {
        REQUIRE_THROWS_AS(Cell(26,1), std::invalid_argument);
    }

    SECTION("abnormal test case for Cell constructor")
    {
        REQUIRE_THROWS_AS(Cell(3,26), std::invalid_argument);
    }

    SECTION("abnormal test case for Cell constructor")
    {
        REQUIRE_THROWS_AS(Cell(26,26), std::invalid_argument);
    }

    SECTION("normal test case for getAdj")
    {
        REQUIRE((cell.getAdj() == 0));
    }

    SECTION("normal test case for setAdj")
    {
        cell.setAdj(2);
        REQUIRE((cell.getAdj() == 2));
    }

    SECTION("normal test case for setAdj")
    {
        cell.setAdj(2);
        REQUIRE((cell.getAdj() == 2));
    }

    SECTION("normal test case for setAdj")
    {
        cell.setAdj(2);
        REQUIRE((cell.getAdj() == 2));
    }

    SECTION("normal test case for getState")
    {
        REQUIRE(cell.getState() == Dead);
    }

    SECTION("normal test case for setState")
    {
        cell.setState(Alive);
        REQUIRE(cell.getState() == Alive);
    }

    SECTION("normal test case for setState")
    {
        cell.setState(Alive);
        cell.setState(Dead);
        REQUIRE(cell.getState() == Dead);
    }
}
