#pragma once

#include <unordered_map>

#include "SMove.hpp"

class APiece {
public:
    enum class EDirection : int {
        PARALLEL,
        DIAGONALLY,
        OTHER
    };
    APiece(const std::pair<short, short>& currentPosition, const std::unordered_map<EDirection, bool>& movePattern);
    virtual void move(const SMove& move) = 0;
    void kill();
    bool isDead() const;
protected:
    std::pair<short, short> currentPosition_;
    bool isValidMove(const SMove& move) const;
private:
    bool isParallel(const SMove& move) const;
    bool isDiagonally(const SMove& move) const;
    bool isOther(const SMove& move) const;
    bool isSingleMove(const SMove& move) const;

    const std::unordered_map<EDirection, bool> movePattern_;
    bool isDead_;
};