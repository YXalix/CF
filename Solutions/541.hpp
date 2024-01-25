#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        while (i < s.size()) {
            int j = min(i + k - 1, (int)s.size() - 1);
            reverseString(s, i, j);
            i += 2 * k;
        }
        return s;
    }

    void reverseString(string &s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
// @lc code=end

inline void test(){
    Solution s;

}