#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rev(int i, int j, vector<int>& nums) {
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        rev(0,n-1,nums);
        rev(0, k-1, nums);
        rev(k,n-1,nums);
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // nums = [1,2,3,4,5,6,7], k = 3
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    s.rotate(nums, k);
    printIntVector(nums);
}