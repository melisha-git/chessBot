#include "Controller.hpp"
#include "Pieces/Pawn.hpp"
#include "Pieces/Rook.hpp"
#include "Pieces/Knight.hpp"
#include "Pieces/Bishop.hpp"
#include "Pieces/Queen.hpp"
#include "Pieces/King.hpp"

#include <cassert>
#include <algorithm>
#include <unordered_map>

Controller::Controller(bool isWhite) : isWhite_(isWhite) {
    for (int i = 0; i < 8; ++i) {
        pieces_.push_back(std::make_shared<Pawn>(std::make_pair<short, short>(i + 1, 2), APiece::EColor::WHITE));
        pieces_.push_back(std::make_shared<Pawn>(std::make_pair<short, short>(i + 1, 7), APiece::EColor::BLACK));
    }
    pieces_.push_back(std::make_shared<Rook>(std::make_pair<short, short>(1, 1), APiece::EColor::WHITE));
    pieces_.push_back(std::make_shared<Rook>(std::make_pair<short, short>(1, 8), APiece::EColor::WHITE));

    pieces_.push_back(std::make_shared<Rook>(std::make_pair<short, short>(8, 1), APiece::EColor::BLACK));
    pieces_.push_back(std::make_shared<Rook>(std::make_pair<short, short>(8, 8), APiece::EColor::BLACK));

    pieces_.push_back(std::make_shared<Knight>(std::make_pair<short, short>(1, 2), APiece::EColor::WHITE));
    pieces_.push_back(std::make_shared<Knight>(std::make_pair<short, short>(1, 7), APiece::EColor::WHITE));

    pieces_.push_back(std::make_shared<Knight>(std::make_pair<short, short>(8, 2), APiece::EColor::BLACK));
    pieces_.push_back(std::make_shared<Knight>(std::make_pair<short, short>(8, 7), APiece::EColor::BLACK));

    pieces_.push_back(std::make_shared<Bishop>(std::make_pair<short, short>(1, 3), APiece::EColor::WHITE));
    pieces_.push_back(std::make_shared<Bishop>(std::make_pair<short, short>(1, 6), APiece::EColor::WHITE));

    pieces_.push_back(std::make_shared<Bishop>(std::make_pair<short, short>(8, 3), APiece::EColor::BLACK));
    pieces_.push_back(std::make_shared<Bishop>(std::make_pair<short, short>(8, 6), APiece::EColor::BLACK));

    pieces_.push_back(std::make_shared<Queen>(std::make_pair<short, short>(1, 4), APiece::EColor::WHITE));
    pieces_.push_back(std::make_shared<Queen>(std::make_pair<short, short>(8, 4), APiece::EColor::BLACK));

    pieces_.push_back(std::make_shared<King>(std::make_pair<short, short>(1, 5), APiece::EColor::WHITE));
    pieces_.push_back(std::make_shared<King>(std::make_pair<short, short>(8, 5), APiece::EColor::BLACK));

    assert(pieces_.size() == 32);
}

std::vector<SMove> Controller::getValidMoves() const {
    std::vector<SMove> ans;
    for (const auto& piece : pieces_) {
        std::unordered_map<int, bool> checked;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (!checked.count(i * 8 + j)) {
                    SMove moving;
                    moving.dest = piece->getPosition();
                    moving.source = std::make_pair<short, short>(i, j);
                    isValidMove(piece, moving, checked, ans);
                }
            }
        }
    }
    return ans;
}

bool Controller::isValidMove(std::shared_ptr<const APiece> piece, const SMove& move, std::unordered_map<int, bool>& checked, std::vector<SMove>& ans) const {
    if (checked.count(move.source.first * 8 + move.source.second)) {
        return checked.at(move.source.first * 8 + move.source.second);
    }
    if (move.source.first > 8 || move.source.first < 1 || move.source.second > 8 || move.source.second < 1) {
        return false;
    }
    checked[move.source.first * 8 + move.source.second] = false;
    if (piece->isDead() || !piece->isValidMove(move)) {
        return false;
    }
    if (piece->getPosition() == move.source || piece->getPosition() != move.dest) {
        return false;
    }

    auto it = std::find_if(pieces_.begin(), pieces_.end(), [&move](std::shared_ptr<const APiece> piece) {
        return move.source == piece->getPosition();
    });

    if (it != pieces_.end() && it->get()->getColor() == piece->getColor()) {
        return false;
    }
    
    if (piece->getType() == APiece::EType::KNIGHT) {
        ans.push_back(move);
        checked[move.source.first * 8 + move.source.second] = true;
        return true;
    }
    
    if (move.isParallel()) {
        short sourceMainPos = move.source.first;
        short sourceOtherPos = move.source.second;
        short currentMainPos = piece->getPosition().first;
        short currentOtherPos = piece->getPosition().second;
        if (move.dest.second != move.source.second) {
            std::swap(sourceMainPos, sourceOtherPos);
            std::swap(currentMainPos, currentOtherPos);
        }

        short step = 1;
        if (sourceMainPos < currentMainPos) {
            step = -1;
        }
        for (short i = sourceMainPos + step; i != currentMainPos; i += step) {
            SMove moving = move;
            if (move.source.first != move.dest.first) {
                moving.source.first = i;
            } else {
                moving.source.second = i;
            }
            if (isValidMove(piece, moving, checked, ans)) {
                checked[move.source.first * 8 + move.source.second] = true;
                ans.push_back(move);
                return true;
            }
        }
    }

    if (move.isDiagonally()) {
        short stepX = move.source.first - move.dest.first;
        short stepY = move.source.second - move.dest.second;

        for (short i = move.source.first + stepX, j = move.source.second + stepY; i != move.dest.first && j != move.dest.second; i += stepX, j += stepY) {
            SMove moving = move;
            moving.source.first = i;
            moving.source.second = j;
            if (isValidMove(piece, moving, checked, ans)) {
                checked[move.source.first * 8 + move.source.second] = true;
                ans.push_back(move);
                return true;
            }
        }
    }

    return false;
}
