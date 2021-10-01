//
// Created by Ikroop Singh Kalsi on 12-09-2021.
//

#include <vector>
#include <cmath>

using namespace std;

/**
 * @name 442. Find All Duplicates in an Array
 * @details Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
 * \n\n You must write an algorithm that runs in O(n) time and uses only constant extra space.
 */
class Solution {
public:

    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> duplicates;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            nums[idx] = -nums[idx];
            if (nums[idx] > 0) {
                duplicates.push_back(abs(nums[i]));
            }
        }
        return duplicates;
    }
};
