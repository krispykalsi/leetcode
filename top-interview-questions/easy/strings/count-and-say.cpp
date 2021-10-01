//
// Created by I$K on 23/09/21.
//

#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 1) {
            return "1";
        }

        auto say = countAndSay(n-1);

        string newSay;
        char currentDigit = say[0];
        int count = 0;
        for (auto digit: say) {
            if (digit == currentDigit) {
                ++count;
            } else {
                newSay += to_string(count) + currentDigit;
                currentDigit = digit;
                count = 1;
            }
        }
        newSay += to_string(count) + currentDigit;
        return newSay;
    }
};
