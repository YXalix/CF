#include "utils.hpp"
#include <unordered_map>
/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n+1,0);
        for (int i = 0;i<n;i++) {
            pre[i+1] = pre[i] + nums[i];
        }
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int i = 0;i<n+1;i++) {
            // 查看当前pre[i] 之前是否存在 pre[i] - k
            if (cnt.contains(pre[i]-k)) {
                ans += cnt[pre[i]-k];
            }
            cnt[pre[i]]++;
        }
        return ans;
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // [6,4,3,1] 10
    vector<int> nums = {1,2,3};
    cout << s.subarraySum(nums,3) << endl;
}