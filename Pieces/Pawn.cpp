#include "Pawn.hpp"

Pawn::Pawn(std::pair<short, short> currentPosition, APiece::EColor color) : APiece(currentPosition, color, APiece::EType::PAWN) {}

bool Pawn::isValidMove(const SMove& move) const {
    short up = move.source.second, down = move.dest.second;
    if (color_ == EColor::BLACK) {
        std::swap(up, down);
    }
    return (up - down == 1 && (move.source.first - move.dest.first <= 1 && move.source.first - move.dest.first >= -1));
}
