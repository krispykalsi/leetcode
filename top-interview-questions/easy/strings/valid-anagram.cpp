//
// Created by I$K on 22/09/21.
//
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> frequencyMap;
        for (auto ch: s) {
            ++frequencyMap[ch];
        }
        for (auto ch: t) {
            --frequencyMap[ch];
        }
        return all_of(frequencyMap.begin(), frequencyMap.end(), [](const pair<char, int> &keyValuePair) {
            return keyValuePair.second == 0;
        });
    }
};
