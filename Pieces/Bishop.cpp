#include "Bishop.hpp"

Bishop::Bishop(std::pair<short, short> currentPosition, APiece::EColor color) : APiece(currentPosition, color, APiece::EType::BISHOP) {}

bool Bishop::isValidMove(const SMove& move) const {
    return move.isDiagonally();
}
