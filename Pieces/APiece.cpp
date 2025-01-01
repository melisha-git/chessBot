#include "APiece.hpp"

APiece::APiece(std::pair<short, short> currentPosition, EColor color, EType pieceType) : currentPosition_(currentPosition), color_(color), type_(pieceType), isDead_(false) {}

void APiece::move(const SMove& move) {
    if (isValidMove(move)) {
        currentPosition_ = move.source;
    }
}

void APiece::kill() {
    isDead_ = true;
}

bool APiece::isDead() const {
    return isDead_;
}

std::pair<short, short> APiece::getPosition() const {
    return currentPosition_;
}

APiece::EColor APiece::getColor() const {
    return color_;
}

APiece::EType APiece::getType() const {
    return type_;
}