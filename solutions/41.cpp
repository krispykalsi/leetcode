//
// Created by Ikroop Singh Kalsi on 12-09-2021.
//
#include <vector>

using namespace std;

/**
 * @name 41. First Missing Positive
 * @details Given an unsorted integer array nums, return the smallest missing positive integer.\n\n
 * You must implement an algorithm that runs in O(n) time and uses constant extra space.
 * @Example1
@code
Input: nums = [1,2,0]
Output: 3
 @endcode

@Example2
@code
Input: nums = [3,4,-1,1]
Output: 2
 @endcode
@Example3
 @code
Input: nums = [7,8,9,11,12]
Output: 1
 @endcode
 */
class Solution {
    void cyclicSort(vector<int> &nums) {
        const auto N = nums.size();
        int i = 0;
        while(i < N) {
            int idx = nums[i] > 0 ? nums[i] - 1 : -1;
            bool isInArrayRange = idx >= 0 && idx < N;
            if (isInArrayRange && nums[idx] != nums[i] && idx != i) {
                swap(nums[i], nums[idx]);
            } else {
                ++i;
            }
        }
    }
public:
    int firstMissingPositive(vector<int> &nums) {
        cyclicSort(nums);
        for (int i = 0; i < nums.size(); ++i) {
            int idx = nums[i] - 1;
            if (idx != i) {
                return i+1;
            }
        }
        return int(nums.size()) + 1;
    }
};
