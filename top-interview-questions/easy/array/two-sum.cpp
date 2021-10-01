//
// Created by I$K on 21/09/21.
//

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int SIZE = int(nums.size());
        unordered_map<int, int> indexMap;

        for (int i = 0; i < SIZE; ++i) {
            int diff = target - nums[i];
            if (indexMap.count(diff) != 0) {
                return vector({indexMap[diff], i});
            } else {
                indexMap[nums[i]] = i;
            }
        }
        return vector({-1,-1});
    }
};
