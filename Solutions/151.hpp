#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int slow = 0;
        int fast = 0;
        for(fast = 0;fast < s.size();fast++)
        {
            if(s[fast] != ' ')
            {
                if(slow != 0) s[slow++] = ' ';
                while(fast < s.size() && s[fast] != ' ')
                {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
        reverse(s.begin(),s.end());
        int right = 0;
        int left = 0;
        while(right < s.size())
        {
            while(right < s.size() && s[right] != ' ') right++;
            reverse(s.begin() + left,s.begin() + right);
            left = ++right;
        }
        return s;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}