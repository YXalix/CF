#include "utils.hpp"
#include <climits>
#include <vector>
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> pre(nums.size()+1);
        pre[0] = 0;
        for(int i = 1; i <= nums.size(); i++){
            pre[i] = pre[i-1] + nums[i-1];
        }
        int max = INT_MIN;
        int min_pre = pre[0];
        for(int i = 1; i <= nums.size(); i++){
            if(pre[i] - min_pre > max){
                max = pre[i] - min_pre;
            }
            if(min_pre > pre[i]){
                min_pre = pre[i];
            }
        }
        return max;
    }
};
// @lc code=end


inline void test(){
	Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(nums) << endl;
}