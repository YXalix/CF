#include "utils.hpp"
#include <utility>
/*
 * @lc app=leetcode.cn id=1696 lang=cpp
 *
 * [1696] 跳跃游戏 VI
 */

// @lc code=start
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        q.emplace(nums[0],0);
        int ans = nums[0];
        for (int i = 1;i<n;i++){
            while (q.top().second + k < i){
                q.pop();
            }
            ans = q.top().first + nums[i];
            q.emplace(ans,i);
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    vector<int> nums{1,-5,-20,4,-1,3,-6,-3};
    cout << s.maxResult(nums,2) << endl;


}