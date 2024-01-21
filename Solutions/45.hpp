#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int end = 0;
        int step = 0;
        int maxpos = 0;
        for (int i = 0;i<n-1;i++){
            maxpos = max(maxpos, i + nums[i]);
            if (i == end){
                end = maxpos;
                step++;
            }
        }
        return step;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    // [2,3,1,1,4]
}