#pragma once

#include <unordered_map>

#include "../SMove.hpp"

class APiece {
public:
    enum class EColor : int {
        WHITE,
        BLACK
    };
    enum class EType : int {
        PAWN,
        ROOK,
        KNIGHT,
        BISHOP,
        QUEEN,
        KING    
    };
    APiece(std::pair<short, short> currentPosition, EColor color, EType pieceType);
    void move(const SMove& move);
    void kill();
    bool isDead() const;
    virtual bool isValidMove(const SMove& move) const = 0;
    std::pair<short, short> getPosition() const;
    EColor getColor() const;
    EType getType() const;
protected:
    std::pair<short, short> currentPosition_;
    const EColor color_;
    const EType type_;
private:
    bool isDead_;
};
