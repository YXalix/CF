#include "utils.hpp"
#include <unordered_map>
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0;i<nums.size();i++) {
            if (m.find(target-nums[i])!=m.end()) {
                return {m[target-nums[i]],i};
            }
            m[nums[i]] = i;
        }
        return {0,0};
    }
};
// @lc code=end


inline void test(){
	Solution s;
}