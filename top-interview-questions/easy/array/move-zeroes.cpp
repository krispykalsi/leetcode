//
// Created by I$K on 21/09/21.
//

#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int SIZE = int(nums.size());
        int leftmostAvailableNonZeroIndex = 0;
        for (int i = 0; i < SIZE; ++i) {
            if (nums[i] != 0) {
                nums[leftmostAvailableNonZeroIndex] = nums[i];
                if (i > leftmostAvailableNonZeroIndex) {
                    nums[i] = 0;
                }
                ++leftmostAvailableNonZeroIndex;
            }
        }
    }
};
