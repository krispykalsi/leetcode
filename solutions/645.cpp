//
// Created by Ikroop Singh Kalsi on 12-09-2021.
//
#include <vector>

using namespace std;

/**
 * @name 645. Set Mismatch
 * @details You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.\n
 * You are given an integer array nums representing the data status of this set after the error.\n
 * Find the number that occurs twice and the number that is missing and return them in the form of an array.
 */
class Solution {
    void cyclicSort(vector<int> &nums) {
        int i = 0;
        while (i < nums.size()) {
            int idx = nums[i] - 1;
            if (nums[idx] != nums[i] && idx != i) {
                swap(nums[idx], nums[i]);
            } else {
                ++i;
            }
        }
    }

public:
    vector<int> findErrorNums(vector<int> &nums) {
        cyclicSort(nums);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] - 1 != i) {
                return {nums[i], i + 1};
            }
        }
        return {};
    }
};
