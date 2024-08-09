#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int ans = 0;
        int pre_max = 0;
        int suf_max = 0;
        while (l < r) {
            pre_max = max(pre_max, height[l]);
            suf_max = max(suf_max, height[r]);
            if (pre_max < suf_max) {
                ans += pre_max - height[l];
                l++;
            } else {
                ans += suf_max - height[r];
                r--;
            }
        }
        return ans;
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // 4,2,0,3,2,5
    vector<int> height = {4,2,0,3,2,5};
    cout << s.trap(height) << endl;
}