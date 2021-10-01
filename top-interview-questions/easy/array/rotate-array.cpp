//
// Created by I$K on 20/09/21.
//
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= int(nums.size());

        if (k == 0 || nums.size() == 1) {
            return;
        }

        vector<int> rotatedNums(nums.end() - k, nums.end());
        int secondHalf = int(nums.size()) - k;
        rotatedNums.insert(rotatedNums.end(), nums.begin(), nums.begin() + secondHalf);

        nums.clear();
        nums.insert(nums.begin(), rotatedNums.begin(), rotatedNums.end());
    }
};
