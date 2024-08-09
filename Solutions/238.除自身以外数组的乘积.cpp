#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n+1, 1);
        for (int i = 1;i<=n;i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }
        int pre = 1;
        for (int i = n-1;i>=0;i--) {
            ans[i] = ans[i] * pre;
            pre = pre * nums[i];
        }
        ans.pop_back();
        return ans;
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // 1,2,3,4
    vector<int> nums = {1,2,3,4};
    printIntVector(s.productExceptSelf(nums));
}