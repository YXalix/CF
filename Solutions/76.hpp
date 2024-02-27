#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n < m) return "";
        unordered_map<char, int> need;
        for(char c : t) need[c]++;
        int left = 0, right = 0;
        int valid = 0;
        string res;
        while (right < n) {
            char c = s[right];
            right++;
            if(need.count(c)){
                if (need[c] > 0) {
                    valid++;
                }
                need[c]--;
            }
            while (valid == m) {
                char d = s[left];
                left++;
                if(need.count(d)){
                    if (need[d] == 0) {
                        if(res.empty() || res.size() > right - left){
                            res = s.substr(left - 1, right - left + 1);
                        }
                        valid--;
                    }
                    need[d]++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

inline void test(){
    Solution s;
//  输入：s = "ADOBECODEBANC", t = "ABC"
//  输出："BANC"
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
}