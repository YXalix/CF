#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> cnt(26,0);
        for (auto item : p) {
            cnt[item - 'a']++;
        }
        int l = 0;
        vector<int> ans;
        int count = p.length();
        for (int r = 0; r<s.size(); r++) {
            int tmp = s[r] - 'a';
            cnt[s[r] - 'a']--;
            while (cnt[tmp] < 0) {
                cnt[s[l]-'a']++;
                l++;
            }
            if (r - l + 1 == count) {
                ans.push_back(l);
            }
        }
        return ans;
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // s = "cbaebabacd", p = "abc"
    string strs = "cbaebabacd";
    string p = "abc";
    vector<int> res = s.findAnagrams(strs, p);
}