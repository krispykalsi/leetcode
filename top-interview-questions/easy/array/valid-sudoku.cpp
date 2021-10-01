//
// Created by I$K on 21/09/21.
//

#include <vector>
#define GRID_SIZE 9
#define BOX_SIZE 3

using namespace std;

class Solution {
    bool isNotValid(char num, bool flagArray[]) {
        if (num != '.') {
            int idx = num - '1';
            if (flagArray[idx]) {
                return true;
            } else {
                flagArray[idx] = true;
                return false;
            }
        } else {
            return false;
        }
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowNumFlag[GRID_SIZE];
        bool columnNumFlag[GRID_SIZE];
        bool boxNumFlag[GRID_SIZE];
        for (int i = 0; i < GRID_SIZE; ++i) {
            memset(rowNumFlag, false, GRID_SIZE);
            memset(columnNumFlag, false, GRID_SIZE);
            memset(boxNumFlag, false, GRID_SIZE);
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (isNotValid(board[i][j], rowNumFlag)) {
                    return false;
                }
                if (isNotValid(board[j][i], columnNumFlag)) {
                    return false;
                }
                int rBoxOffset = (i / BOX_SIZE) * BOX_SIZE;
                int cBoxOffset = (i % BOX_SIZE) * BOX_SIZE;
                int r = rBoxOffset + j / BOX_SIZE;
                int c = cBoxOffset + j % BOX_SIZE;
                if (isNotValid(board[r][c], boxNumFlag)) {
                    return false;
                }
            }
        }
        return true;
    }
};
