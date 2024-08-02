#include "utils.hpp"
#include <string>
#include <vector>
/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> left(26, 0), isAns(26, 0);
        for (auto c : s) {
            left[c - 'a']++;
        }
        string ans;
        for (auto c : s) {
            if (!isAns[c - 'a']) {
                while (!ans.empty() && ans.back() > c && left[ans.back() - 'a'] > 0) {
                    isAns[ans.back() - 'a'] = 0;
                    ans.pop_back();
                }
                ans.push_back(c);
                isAns[c - 'a'] = 1;
            }
            left[c - 'a']--;
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}