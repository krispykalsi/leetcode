//
// Created by I$K on 23/09/21.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
    string helper(vector<string>& strs, const int &N, int i = 0) {
        if (i >= N) {
            return "";
        }

        char ch = strs[0][i];
        for (const auto &s: strs) {
            if (s[i] != ch) {
                return "";
            }
        }

        return ch + helper(strs, N, i+1);
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        int shortestStringSize = INT_MAX;
        for (const auto &s: strs) {
            shortestStringSize = min(shortestStringSize, int(s.size()));
        }
        return helper(strs, shortestStringSize);
    }
};
