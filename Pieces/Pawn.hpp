#pragma once

#include "APiece.hpp"

class Pawn : public APiece {
    Pawn(std::pair<short, short> currentPosition, APiece::EColor color);

    bool isValidMove(const SMove& move) const override final;
};