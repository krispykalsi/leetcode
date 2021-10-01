//
// Created by I$K on 20/09/21.
//
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};
