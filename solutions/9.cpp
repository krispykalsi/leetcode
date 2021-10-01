//
// Created by I$K on 30/09/21.
//
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        auto s = std::to_string(x);
        const auto SIZE = s.size();
        for(size_t i = 0, j = SIZE-1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};
