#include "utils.hpp"
#include <unordered_map>
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dist;
        int left = -1;
        int res = 0;
        int len = s.size();
        for (int right = 0; right< len;right++){
            if (dist.find(s[right]) != dist.end()) {
                left = max(left, dist[s[right]]); // update left
            }
            dist[s[right]] = right; // update new localtion
            res = max(res, right - left);
        }
        return res;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}