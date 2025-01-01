#pragma once

#include <vector>
#include <memory>

#include "Pieces/APiece.hpp"
#include "SMove.hpp"

class Controller {
public:
    explicit Controller(bool isWhite);    
    std::vector<SMove> getValidMoves() const;
private:
    bool isValidMove(std::shared_ptr<const APiece> piece, const SMove& move, std::unordered_map<int, bool>& checked, std::vector<SMove>& ans) const;

    bool isWhite_;
    std::vector<std::shared_ptr<APiece>> pieces_;
};
