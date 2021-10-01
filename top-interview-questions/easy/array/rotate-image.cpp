//
// Created by I$K on 22/09/21.
//
#include <vector>

using namespace std;

class Solution {
    void transpose(vector<vector<int>>& matrix, const int N) {
        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                if (i == j) {
                    continue;
                }
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void reverse(vector<vector<int>>& matrix, const int N) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N / 2; ++j) {
                swap(matrix[i][j], matrix[i][(N-1) - j]);
            }
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        const int N = int(matrix.size());
        transpose(matrix, N);
        reverse(matrix, N);
    }
};
