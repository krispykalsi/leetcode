//
// Created by I$K on 20/09/21.
//
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currentNum = INT_MAX;
        for (auto it = nums.begin(); it != nums.end();) {
            if (*it == currentNum) {
                nums.erase(it);
            } else {
                currentNum = *it;
                ++it;
            }
        }
        return int(nums.size());
    }
};
