#include <iostream>
#include <vector>

#include <ranges>
#include <algorithm>

// https://www.linkedin.com/posts/nikolai-kutiavin_cpp-cpp20-leetcode-activity-7270346267908608001-tKJ4/?utm_source=share&utm_medium=member_desktop
// 
class Solution {
public:
    std::string addSpaces(std::string s, std::vector<int>& spaces) {
        auto originalSize = s.size();

    // Here the original string is used for the transformation,
    // so make this big enough to fit result
    s.resize(s.size() + spaces.size());
    
    // Split the original string into slices, that then would be copied.
    // The idea here, that we take a slice starting from the end, copy it,
    // then insert space and continue with the next one.
    auto substrings = spaces
    | std::views::reverse
    | std::views::transform([lastPositionInRange = originalSize, view = std::string_viev( )](int space) mutable{
        const auto tmp = lastPositionInRange; lastPositionInRange = space;
        return view.substr(space, tmp - space);
    });

    // No its time to do a copy of slices.
    // Source and destination ranges are overlaping, for that reason it's important to
    // do a copy in the reverse order.
    std::ranges::fold_left(substrings, s.rbegin(), [](auto write, auto view){
    auto out = std::ranges::copy(view | std::views::reverse, write).out;
        *out = ' ';
        ++out;
        return out;
    });
    return s;
    }
};

