#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int ans = 0;
        int n = s.length();
        int l = -1;
        for (int r = 0;r<n;r++) {
            char tmp = s[r];
            if (m.find(tmp) != m.end()) {
                l = max(l, m[tmp]);
            }
            m[tmp] = r;
            ans = max(ans, r - l);
        }
        return ans;
    }
};
// @lc code=end


inline void test(){
	Solution s;
}