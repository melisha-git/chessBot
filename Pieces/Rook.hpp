#pragma once

#include "APiece.hpp"

class Rook : public APiece {
    Rook(std::pair<short, short> currentPosition, APiece::EColor color);

    bool isValidMove(const SMove& move) const override final;
};