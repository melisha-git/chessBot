#include "../../Pieces/Bishop.hpp"
#include <gtest/gtest.h>

TEST(BishopTests, IsValidMoveTest) {
    auto position = std::make_pair<short, short>(8, 3);
    Bishop bishop(position, APiece::EColor::BLACK);
    SMove move;
    move.dest = position;
    move.source.first = position.first - 2;
    move.source.second = position.second - 2;
    ASSERT_TRUE(bishop.isValidMove(move));
    bishop.move(move);
    ASSERT_FALSE(bishop.isValidMove(move));
    move.source.second = 2;
    ASSERT_FALSE(bishop.isValidMove(move));
}
