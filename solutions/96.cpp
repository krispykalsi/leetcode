#include <vector>

using namespace std;

class Solution {
    vector<int> memo = vector<int>(20, -1);
public:
    int numTrees(int n) {
        if (memo[n] != -1) {
            return memo[n];
        }
        if (n == 0) {
            return 1;
        }
        auto trees = 0;
        for (int i = 0; i < n; i++) {
            trees += numTrees(i) * numTrees(n-1-i);
        }
        memo[n] = trees;
        return trees;
    }
};