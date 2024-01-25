#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> next(s.size(), 0);
        getNext(s, next);
        int n = s.size();
        int len = next[n - 1];
        return len > 0 && n % (n - len) == 0;
    }

    void getNext(string needle,vector<int>& next) {
        next[0] = 0;
        int i = 1;
        while (i < needle.size()) {
            int j = next[i - 1];
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];
            }
            if (needle[i] == needle[j]) {
                next[i] = j + 1;
            } else {
                next[i] = 0;
            }
            i++;
        }
    }
};
// @lc code=end

inline void test(){
    Solution s;

}