//
// Created by I$K on 22/09/21.
//

#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        const int SIZE = int(s.size());
        for (int i = 0; i < SIZE / 2; ++i) {
            swap(s[i], s[SIZE-1 - i]);
        }
    }
};
