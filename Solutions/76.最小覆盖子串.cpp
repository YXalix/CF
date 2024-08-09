#include "utils.hpp"
#include <climits>
#include <unordered_map>
#include <utility>
#include <vector>
/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }
        unordered_map<char, int> cnt_t;
        // 代表当前有多少种不同的字母
        int count = 0;
        for (auto c : t) {
            count += cnt_t[c]==0;
            cnt_t[c]++;
        }
        int l = -1;
        // [start, start + len]
        pair<int, int> ans = {-1,INT_MAX};
        for (int r = 0;r < s.size();r++) {
            char tmp = s[r];
            if (cnt_t.contains(tmp)) {
                // 如果cnt_t == 1 说明已经完全覆盖该字母
                if (cnt_t[tmp] == 1) {
                    count--;
                }
                cnt_t[tmp]--;
                // 如果count == 1 说明刚好完全覆盖
                while (count == 0) {
                    if (r - l < ans.second) {
                        ans.first = l;
                        ans.second = r - l;
                    }
                    l++;
                    char x = s[l];
                    if (cnt_t.contains(x)) {
                        // 如果 cnt_t == 0 说明 即将不能覆盖
                        if (cnt_t[x] == 0) {
                            count++;
                        }
                        cnt_t[x]++;
                    }
                }
            }
        }
        if (ans.second == INT_MAX) {
            return "";
        }
        return s.substr(ans.first + 1, ans.second);
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // s = "ADOBECODEBANC", t = "ABC"
    string strs = "a", t = "b";
    cout << s.minWindow(strs, t) << endl;
}