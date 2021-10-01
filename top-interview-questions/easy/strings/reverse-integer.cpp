//
// Created by I$K on 22/09/21.
//
#include <string>

using namespace std;

class Solution {
    void reverse(string &num, bool hasMinusSign = false) {
        const int SIZE = int(num.size());
        if (hasMinusSign) {
            for (int i = 1; i <= SIZE/2 ; ++i) {
                swap(num[i], num[(SIZE-1) - i + 1]);
            }
        } else {
            for (int i = 0; i < SIZE/2 ; ++i) {
                swap(num[i], num[(SIZE-1) - i]);
            }
        }
    }
public:
    int reverse(int x) {
        auto num = to_string(x);
        reverse(num, num[0] == '-');
        try {
            return stoi(num);
        } catch (out_of_range &e) {
            return 0;
        }
    }
};
