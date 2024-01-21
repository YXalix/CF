#include "utils.hpp"
#include <unordered_map>
/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;
        for (auto& num1 : nums1) {
            for (auto& num2 : nums2) {
                m[num1 + num2]++;
            }
        }
        int ans = 0;
        for (auto& num3 : nums3) {
            for (auto& num4 : nums4) {
                if (m.count(-num3 - num4)) {
                    ans += m[-num3 - num4];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}