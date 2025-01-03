#pragma once

#include <utility>
#include <cmath>

struct SMove {
    std::pair<short, short> dest = std::make_pair<short, short>(0, 0);
    std::pair<short, short> source = std::make_pair<short, short>(0, 0);

    bool isParallel() const {
        return (std::abs(dest.first - source.first) != 0 
            && std::abs(dest.second - source.second) == 0) 
            || (std::abs(dest.first - source.first) == 0 
            && std::abs(dest.second - source.second) != 0);
    }

    bool isDiagonally() const {
        return (std::abs(dest.first - source.first) == std::abs(dest.second - source.second)) 
            && std::abs(dest.first - source.first) != 0;
    }

    bool isZeroMove(std::pair<short, short> position) const {
        return dest != position || source == position;
    }
};
