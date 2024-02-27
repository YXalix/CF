#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int m = s1.size();
        if(n < m) return false;
        unordered_map<char, int> need, window;
        for(char c : s1) need[c]++;
        int left = 0, right = 0;
        int valid = 0;
        while (right < n) {
            char c = s2[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            while (right - left >= m) {
                if(right - left == m && valid == need.size()) return true;
                char d = s2[left];
                left++;
                if(need.count(d)){
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return false;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    // "abcdxabcde"
    // "abcdeabcdx"
    cout << s.checkInclusion("abcdxabcde", "abcdeabcdx") << endl;
}