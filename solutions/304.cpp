#include <vector>

using namespace std;

class NumMatrix {
    vector<vector<int>> sumMatrix;
    int columns;
    int rows;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        if (rows <= 0) {
            throw runtime_error("Empty grid");
        }
        columns = matrix[0].size();
        sumMatrix = vector<vector<int>>(rows, vector<int>(columns, 0));

        int sum = 0;
        for (auto i = 0; i < columns; i++) {
            sum += matrix[0][i];
            sumMatrix[0][i] = sum;
        }
        for (auto i = 1; i < rows; i++) {
            sum = 0;
            for (auto j = 0; j < columns; j++) {
                sum += matrix[i][j];
                sumMatrix[i][j] = sum  + sumMatrix[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 > row2 || col1 > col2 || row2 >= rows || col2 >= columns) {
            throw runtime_error("incorrect region coordinates");
        }
        int sum = sumMatrix[row2][col2];
        if (col1 != 0) {
            sum -= sumMatrix[row2][col1-1];
        }
        if (row1 != 0) {
            sum -= sumMatrix[row1-1][col2];
        }
        if (row1 != 0 && col1 != 0) {
            sum += sumMatrix[row1-1][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */