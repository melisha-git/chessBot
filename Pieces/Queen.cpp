#include "Queen.hpp"

Queen::Queen(std::pair<short, short> currentPosition, APiece::EColor color) : APiece(currentPosition, color, APiece::EType::QUEEN) {}

bool Queen::isValidMove(const SMove& move) const {
    return !move.isZeroMove(currentPosition_) && move.isDiagonally() || move.isParallel();
}
