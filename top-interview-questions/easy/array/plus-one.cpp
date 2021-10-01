//
// Created by I$K on 21/09/21.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const int N = int(digits.size());
        digits[N-1] = (digits[N-1] + 1) % 10;
        int carry = digits[N-1] == 0 ? 1 : 0;
        for (int i = N-2; i >= 0; --i) {
            digits[i] = (digits[i] + carry) % 10;
            carry = digits[i] == 0 && carry == 1 ? 1 : 0;
        }
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
