#include "utils.hpp"
#include <cstddef>
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
        for (size_t i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) {
                return {m[target - nums[i]], (int)i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

inline void test(){
    Solution s;

}