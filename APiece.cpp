#include "APiece.hpp"

#include <cmath>

APiece::APiece(const std::pair<short, short>& currentPosition, const std::unordered_map<EDirection, bool>& movePattern) : currentPosition_(currentPosition), movePattern_(movePattern), isDead_(false) {}

void APiece::kill() {
    isDead_ = true;
}

bool APiece::isDead() const {
    return isDead_;
}

// PROTECTED

bool APiece::isValidMove(const SMove& move) const {
    if (currentPosition_ != move.dest) {
        return false;
    }

    if (isParallel(move) && movePattern_.count(EDirection::PARALLEL)) {
        if (movePattern_.at(EDirection::PARALLEL) && !isSingleMove(move)) {
            return false;
        }
        return true;
    }

    if (isDiagonally(move) && movePattern_.count(EDirection::DIAGONALLY)) {
        if (movePattern_.at(EDirection::DIAGONALLY) && !isSingleMove(move)) {
            return false;
        }
        return true;
    }

    if (isOther(move) && movePattern_.count(EDirection::OTHER)) {
        return true;
    }
    return false;
}

// PRIVATE

bool APiece::isParallel(const SMove& move) const {
    return (move.dest.first == move.source.first 
            && move.dest.second != move.source.second) 
        || (move.dest.first != move.source.first 
            && move.dest.second == move.source.second);
}

bool APiece::isDiagonally(const SMove& move) const {
    return std::abs(move.dest.first - move.source.first) == std::abs(move.dest.second - move.source.second);
}

bool APiece::isOther(const SMove& move) const {
    return (std::abs(move.dest.first - move.source.first) == 2
            && std::abs(move.dest.second - move.source.second) == 1) 
        || (std::abs(move.dest.first - move.source.first) == 1
            && std::abs(move.dest.second - move.source.second) == 2);
}

bool APiece::isSingleMove(const SMove& move) const {
    return (isParallel(move) && (std::abs(move.dest.first - move.source.first) == 1 || std::abs(move.dest.second - move.source.second) == 1))
        && (isDiagonally(move) && (std::abs(move.dest.first - move.source.first) == 1 && std::abs(move.dest.second - move.source.second) == 1));
}