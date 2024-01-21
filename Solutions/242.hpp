#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> count(26, 0);
        for (auto i : s) {
            count[i-'a']++;
        }
        for (auto i : t) {
            count[i-'a']--;
        }
        for (int i = 0;i<26;i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

inline void test(){
    Solution s;
// 输入: s = "rat", t = "car"
// 输出: false
    cout << s.isAnagram("rat", "car") << endl;
}