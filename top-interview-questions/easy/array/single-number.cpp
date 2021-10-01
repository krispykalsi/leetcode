//
// Created by I$K on 20/09/21.
//
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ans ^= nums[i];
        }
        return ans;
    }
};
