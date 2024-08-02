#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        for (int i = 0;i<nums.size();i++){
            if (nums[i] != 0) {
                nums[cur] = nums[i];
                cur++;
            }
        }
        for (;cur<nums.size();cur++){
            nums[cur] = 0;
        }
    }
};
// @lc code=end


inline void test(){
	Solution s;
}