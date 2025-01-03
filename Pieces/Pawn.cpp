#include "Pawn.hpp"

Pawn::Pawn(std::pair<short, short> currentPosition, APiece::EColor color) : APiece(currentPosition, color, APiece::EType::PAWN) {}

bool Pawn::isValidMove(const SMove& move) const {
    short up = move.source.second, down = move.dest.second;
    if (color_ == EColor::BLACK) {
        std::swap(up, down);
    }
    short maxMove = 1;
    if ((color_ == APiece::EColor::BLACK && currentPosition_.second == 7) || color_ == APiece::EColor::WHITE && currentPosition_.second == 2) {
        maxMove = 2;
    }
    return !move.isZeroMove(currentPosition_) 
        && (up - down <= maxMove && (move.source.first - move.dest.first <= 1 && move.source.first - move.dest.first >= -1));
}
