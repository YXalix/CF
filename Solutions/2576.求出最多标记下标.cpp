#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=2576 lang=cpp
 *
 * [2576] 求出最多标记下标
 */

// @lc code=start
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        for (int j = n / 2; j < n; j++) {
            if (2 * nums[i] <= nums[j]) {
                i++;
            }
        }
        return i * 2;
    }
};
// @lc code=end


inline void test(){
	Solution s;
}