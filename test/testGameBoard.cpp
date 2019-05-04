/**
 * \file testGameBoard.cpp
 * \author Leon So | macid: sol4
 * \date 2019-04-13
 */
#include "catch.h"
#include "CellTypes.h"
#include "Cell.h"
#include "GameBoard.h"
#include "View.h"
#include "CellGrid.h"

#include <stdexcept>

TEST_CASE("tests for GameBoard", "[GameBoard]")
{
    Board board("input.txt");

    SECTION("normal test case for Board constructor")
    {
        Board board2("input.txt");
        REQUIRE((
            board.getCell(11,10).getState() == Dead &&
            board.getCell(13,11).getState() == Dead &&
            board.getCell(10,11).getState() == Alive &&
            board.getCell(11,12).getState() == Alive &&
            board.getCell(12,11).getState() == Alive
        ));
    }

    SECTION("abnormal test case for Board constructor")
    {
        REQUIRE_THROWS_AS(Board("input2.txt"),std::invalid_argument);
    }

    SECTION("normal test case for getCell")
    {
        REQUIRE((
            board.getCell(0,1).getX() == 0 &&
            board.getCell(0,1).getY() == 1 &&
            board.getCell(0,1).getState() == Dead &&
            board.getCell(0,0).getAdj() == 0
        ));
    }

    SECTION("abnormal test case for getCell")
    {
        REQUIRE_THROWS_AS(board.getCell(26,1).getX() == 0, std::out_of_range);
    }

    SECTION("abnormal test case for getCell")
    {
        REQUIRE_THROWS_AS(board.getCell(5,26).getX() == 0, std::out_of_range);
    }

    SECTION("normal test for nextState")
    {
        board.nextState();
        REQUIRE((
            board.getCell(11,10).getState() == Alive &&
            board.getCell(13,11).getState() == Alive &&
            board.getCell(10,11).getState() == Dead
        ));
    }

    SECTION("normal test for nextState")
    {
        board.nextState();
        board.nextState();
        REQUIRE((
            board.getCell(12,10).getState() == Alive &&
            board.getCell(13,11).getState() == Alive &&
            board.getCell(13,10).getState() == Dead
        ));
    }
}
