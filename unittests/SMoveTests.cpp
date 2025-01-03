#include "../SMove.hpp"
#include <gtest/gtest.h>

TEST(SMoveTest, IsZeroMove) {
    SMove move;

    ASSERT_TRUE(move.isZeroMove(move.dest));
    ASSERT_TRUE(move.isZeroMove(move.source));
    ASSERT_TRUE(move.isZeroMove(std::make_pair<short, short>(2, 2)));

    move.dest = std::make_pair<short, short>(1, 1);
    move.source = std::make_pair<short, short>(3, 3);

    ASSERT_FALSE(move.isZeroMove(move.dest));
    ASSERT_TRUE(move.isZeroMove(move.source));

    ASSERT_TRUE(move.isZeroMove(std::make_pair<short, short>(2, 2)));

    move.source = move.dest;

    ASSERT_TRUE(move.isZeroMove(move.dest));
    ASSERT_TRUE(move.isZeroMove(move.source));

    ASSERT_TRUE(move.isZeroMove(std::make_pair<short, short>(2, 2)));
}

void parallelMoveTestUtil(std::pair<short, short> dest) {
    SMove move;

    ASSERT_FALSE(move.isParallel());

    move.dest = dest;

    for (int i = 1; i <= 8; ++i) {
        if (i == dest.first || i == dest.second) {
            continue;
        }
        move.source = std::make_pair<short, short>(i, i);
        ASSERT_FALSE(move.isParallel());
    }
    
    for (int i = 1; i <= 8; ++i) {
        if (i == dest.first) {
            continue;
        }
        move.source = std::make_pair<short, short>(static_cast<int>(dest.first), i);
        if (i == dest.second) {
            ASSERT_FALSE(move.isParallel());
        } else {
            ASSERT_TRUE(move.isParallel());
        }
    }

    for (int i = 1; i <= 8; ++i) {
        if (i == dest.second) {
            continue;
        }
        move.source = std::make_pair<short, short>(i, static_cast<int>(dest.second));
        if (i == dest.first) {
            ASSERT_FALSE(move.isParallel());
        } else {
            ASSERT_TRUE(move.isParallel());
        }
    }
}

TEST(SMoveTest, IsParallelMove) {
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            parallelMoveTestUtil(std::make_pair<short, short>(i, j));
        }
    }
}

void diagonallyMoveTestUtil(std::pair<short, short> dest) {
    SMove move;

    ASSERT_FALSE(move.isDiagonally());

    move.dest = dest;

    for (int i = 1; i <= 8; ++i) {
        move.source = std::make_pair<short, short>(dest.first + i, dest.second + i);
        ASSERT_TRUE(move.isDiagonally());
        move.source = std::make_pair<short, short>(dest.first + i, dest.second - i);
        ASSERT_TRUE(move.isDiagonally());
        move.source = std::make_pair<short, short>(dest.first - i, dest.second + i);
        ASSERT_TRUE(move.isDiagonally());
        move.source = std::make_pair<short, short>(dest.first - i, dest.second - i);
        ASSERT_TRUE(move.isDiagonally());
    }

    for (int i = 0; i <= 8; ++i) {
        move.source = std::make_pair<short, short>(dest.first + i, static_cast<int>(dest.second));
        ASSERT_FALSE(move.isDiagonally());
        move.source = std::make_pair<short, short>(dest.first - i, static_cast<int>(dest.second));
        ASSERT_FALSE(move.isDiagonally());
        move.source = std::make_pair<short, short>(static_cast<int>(dest.first), dest.second + i);
        ASSERT_FALSE(move.isDiagonally());
        move.source = std::make_pair<short, short>(static_cast<int>(dest.first), dest.second - i);
        ASSERT_FALSE(move.isDiagonally());
    }
}

TEST(SMoveTest, IsDiagonally) {
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            diagonallyMoveTestUtil(std::make_pair<short, short>(i, j));
        }
    }
}