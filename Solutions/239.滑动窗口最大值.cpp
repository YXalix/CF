#include "utils.hpp"
#include <utility>
#include <vector>
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0;i<nums.size();i++) {
            // 入
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            // 出, 说明已经过期
            if (i - q.front() >= k) {
                q.pop_front();
            }
            // 记录
            if (i >= k - 1) {
                ans.push_back(q.front());
            }
        }
        return ans;
    }
};
// @lc code=end


inline void test(){
	Solution s;
}