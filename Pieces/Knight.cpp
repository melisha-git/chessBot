#include "Knight.hpp"

#include <cmath>

Knight::Knight(std::pair<short, short> currentPosition, APiece::EColor color) : APiece(currentPosition, color, APiece::EType::KNIGHT) {}

bool Knight::isValidMove(const SMove& move) const {
    return !move.isZeroMove(currentPosition_) 
        && (std::abs(move.dest.first - move.source.first) == 2 
        && std::abs(move.dest.second - move.source.second) == 1)
        || (std::abs(move.dest.first - move.source.first) == 1 
        && std::abs(move.dest.second - move.source.second) == 2);
}
