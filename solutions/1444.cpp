#include <vector>
#include <string>
#define MOD 1000000007

using namespace std;

class ApplePizza {
    vector<vector<int>> sumMatrix;
    int columns;
    int rows;

public:
    ApplePizza(const vector<string>& pizza) {
        rows = pizza.size();
        if (rows <= 0) {
            throw runtime_error("Empty grid");
        }
        columns = pizza[0].size();
        sumMatrix = vector<vector<int>>(rows, vector<int>(columns, 0));

        int sum = 0;
        for (auto i = 0; i < columns; i++) {
            sum += pizza[0][i] == 'A';
            sumMatrix[0][i] = sum;
        }
        for (auto i = 1; i < rows; i++) {
            sum = 0;
            for (auto j = 0; j < columns; j++) {
                sum += pizza[i][j] == 'A';
                sumMatrix[i][j] = sum  + sumMatrix[i-1][j];
            }
        }
    }
    
    bool containsAppleInRegion(int row1, int col1, int row2, int col2) {
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
        return sum > 0;
    }
};

class Solution {
    ApplePizza* applePizza;
    int rows, columns;
    vector<vector<vector<int>>>* memo;

    int dp(int i, int j, int k) {
        if ((*memo)[i][j][k] != -1) {
            return (*memo)[i][j][k];
        }
        bool hasAppleInLeftOverRegion = applePizza -> containsAppleInRegion(i, j, rows-1, columns-1);
        if (!hasAppleInLeftOverRegion) {
            return 0;
        } 
        if (k == 0) {
            return 1;
        }
        
        int waysToCut = 0;
        for (int row = i; row < rows-1; row++) {
            bool hasAppleInUpperSide = applePizza -> containsAppleInRegion(i, j, row, columns-1);
            if (hasAppleInUpperSide) {
                waysToCut = (waysToCut + dp(row+1, j, k-1)) % MOD;
            }
        }
        for (int column = j; column < columns-1; column++) {
            bool hasAppleInLeftSide = applePizza -> containsAppleInRegion(i, j, rows-1, column);
            if (hasAppleInLeftSide) {
                waysToCut = (waysToCut + dp(i, column+1, k-1)) % MOD;
            }
        }
        (*memo)[i][j][k] = waysToCut;
        return waysToCut;
    }
public:
    int ways(const vector<string>& pizza, int k) {
        applePizza = new ApplePizza(pizza);
        rows = pizza.size();
        columns = rows > 0 ? pizza[0].size() : 0;
        memo = new vector<vector<vector<int>>>(rows, vector<vector<int>>(columns, vector<int>(k, -1)));
        auto ans = dp(0, 0, k-1);
        delete applePizza;
        delete memo;
        return ans;
    }
};