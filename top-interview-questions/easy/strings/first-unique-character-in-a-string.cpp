//
// Created by I$K on 22/09/21.
//
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> frequencyMap;
        for (auto ch: s) {
            frequencyMap[ch] += 1;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (frequencyMap[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
