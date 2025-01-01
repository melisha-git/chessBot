#pragma once

#include "APiece.hpp"

class Queen : public APiece {
public:
    Queen(std::pair<short, short> currentPosition, APiece::EColor color);

    bool isValidMove(const SMove& move) const override final;
};
