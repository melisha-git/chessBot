#include "Rook.hpp"

#include <cmath>

Rook::Rook(std::pair<short, short> currentPosition, APiece::EColor color) : APiece(currentPosition, color, APiece::EType::ROOK) {}

bool Rook::isValidMove(const SMove& move) const {
    return move.isParallel();
}
