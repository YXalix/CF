#include "utils.hpp"
#include <stack>
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        unordered_map <char, char> map {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack <char> st;
        for (char ch : s)
        {
            if (map.count(ch))
            {
                if(st.empty() || st.top() != map[ch]) return false;
                else st.pop();
            }
            else st.push(ch);
        }
        if (!st.empty()) return false;
        else return true;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}