#pragma once

#include <utility>
#include <cmath>

struct SMove {
    std::pair<short, short> dest;
    std::pair<short, short> source;

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
};
