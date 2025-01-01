#pragma once

#include "APiece.hpp"

class King : public APiece {
public:
    King(std::pair<short, short> currentPosition, APiece::EColor color);

    bool isValidMove(const SMove& move) const override final;
};
