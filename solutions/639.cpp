#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

class Solution {
    inline bool isLessThan26(const char& a, const char& b) {
        return a == '1' || (a == '2' && b <= '6');
    }
public:
    int numDecodings(const string& str) {
        auto size = str.size();
        vector<long long> dp(size + 1);
        dp[0] = 1;
        if (size > 0) {
            switch (str.back()) {
            case '*': dp[1] = 9; break;
            case '0': dp[1] = 0; break;
            default: dp[1] = 1; break;
            }
        }
        for (int i = size - 2, len = 2; i >= 0; i--, len++) {
            if (str[i] != '0') {
                auto ways1 = dp[len - 1];
                if (str[i] == '*') {
                    ways1 = (9 * ways1) % MOD;
                }
                auto ways2 = 0;
                if (str[i+1] == '*') {
                    int multiplier = 0;
                    switch (str[i]) {
                    case '*': multiplier = 15; break;
                    case '1': multiplier = 9; break;
                    case '2': multiplier = 6; break;
                    }
                    if (multiplier != 0) {
                        ways2 = (multiplier * dp[len - 2]) % MOD;
                    }
                } else if (str[i] == '*') {
                    int multiplier = str[i+1] <= '6' ? 2 : 1;
                    ways2 = (multiplier * dp[len - 2]) % MOD;
                } else if (isLessThan26(str[i], str[i+1])) {
                    ways2 = dp[len - 2];
                }
                dp[len] = (ways1 + ways2) % MOD;
            } else {
                dp[len] = 0;
            }
        }
        return dp[size];
    }
};
