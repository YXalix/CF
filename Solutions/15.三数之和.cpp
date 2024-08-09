#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for (int i = 0;i<nums.size();i++) {
            if (i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            int target = -nums[i];
            int l = i+1, r = nums.size()-1;
            while (l<r) {
                if (nums[l]+nums[r]<target) {
                    l++;
                } else if (nums[l]+nums[r]>target) {
                    r--;
                } else {
                    res.push_back({nums[i],nums[l],nums[r]});
                    for (l++;l<r && nums[l]==nums[l-1];l++);
                    for (r--;l<r && nums[r]==nums[r+1];r--);
                }
            }
        }
        return res;
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // [-1,0,1,2,-1,-4]
    vector<int> nums = {-1,0,1,2,-1,-4};
    s.threeSum(nums);
    for (auto &vec:s.threeSum(nums)) {
        printIntVector(vec);
    }
}