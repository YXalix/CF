#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = nums[0];
        int ans = dp[1];
        for(int i = 2; i < n-1; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            ans = max(ans, dp[i]);
        }
        dp[0] = 0;
        dp[1] = nums[1];
        ans = max(ans, dp[1]);
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}