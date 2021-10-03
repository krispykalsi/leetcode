//
// Created by Ikroop Singh Kalsi on 10/2/2021.
//
#include <string>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        const auto SIZE1 = s1.size();
        const auto SIZE2 = s2.size();
        int **dp = new int*[SIZE1+1];
        for (int i = 0; i <= SIZE1; ++i) {
            dp[i] = new int[SIZE2+1];
        }

        for (int i = 0; i <= SIZE1; ++i) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= SIZE2; ++i) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= SIZE1; ++i) {
            for (int j = 1; j <= SIZE2; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return dp[SIZE1][SIZE2];
    }
};