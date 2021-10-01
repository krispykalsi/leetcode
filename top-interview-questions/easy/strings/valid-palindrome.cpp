//
// Created by I$K on 22/09/21.
//

#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string corrected;
        for (auto &ch: s) {
            ch = char(tolower(ch));
            if(ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9') {
                corrected += ch;
            }
        }

        const int SIZE = int(corrected.size());
        for (int i = 0; i < SIZE / 2; ++i) {
            if (corrected[i] != corrected[(SIZE-1) - i]) {
                return false;
            }
        }

        return true;
    }
};
