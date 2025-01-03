#include "King.hpp"

King::King(std::pair<short, short> currentPosition, APiece::EColor color) : APiece(currentPosition, color, APiece::EType::KING) {}

bool King::isValidMove(const SMove& move) const {
    return !move.isZeroMove(currentPosition_)
        && (move.isParallel() || move.isDiagonally()) 
        && std::abs(move.dest.first - move.source.first) <= 1
        && std::abs(move.dest.second - move.source.second) <= 1;
}
