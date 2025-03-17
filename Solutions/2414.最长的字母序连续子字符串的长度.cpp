#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=2414 lang=cpp
 *
 * [2414] 最长的字母序连续子字符串的长度
 */

// @lc code=start
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int res = 1;
        int cur = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] - s[i - 1] == 1) {
                cur++;
            } else {
                res = max(res, cur);
                cur = 1;
            }
        }
        return max(res, cur);
    }
};
// @lc code=end


inline void test(){
	Solution s;
}