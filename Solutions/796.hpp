#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */

// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        if(s.size() == 0) return true;
        int n = s.size();
        for(int i = 0;i < n;i++)
        {
            if(s[i] == goal[0])
            {
                int j = 0;
                while(j < n && s[(i + j) % n] == goal[j]) j++;
                if(j == n) return true;
            }
        }
        return false;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}