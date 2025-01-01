#pragma once

#include "APiece.hpp"

class Bishop : public APiece {
    Bishop(std::pair<short, short> currentPosition, APiece::EColor color);

    bool isValidMove(const SMove& move) const override final;
};