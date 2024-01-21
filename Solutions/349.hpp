#include "utils.hpp"
#include <unordered_map>
/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m;
        for (auto& num : nums1) {
            m.insert(num);
        }
        vector<int> ans;
        for (auto& num : nums2) {
            if (m.count(num)) {
                ans.push_back(num);
                m.erase(num);
            }
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}