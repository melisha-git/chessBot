#pragma once

#include "APiece.hpp"

class Knight : public APiece {
    Knight(std::pair<short, short> currentPosition, APiece::EColor color);

    bool isValidMove(const SMove& move) const override final;
};