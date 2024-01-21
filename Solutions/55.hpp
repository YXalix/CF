#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxpos = 0;
        for (int i = 0;i<n;i++){
            if (i <= maxpos){
                maxpos = max(i+nums[i], maxpos);
                if (maxpos >= n-1){
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}