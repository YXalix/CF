#include "utils.hpp"
#include <stack>
#include <string>
/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for (auto c : s) {
            if (ans.empty() || ans.back() != c) {
                ans.push_back(c);
            } else {
                ans.pop_back();
            }
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}