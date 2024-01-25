#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        vector<int> next(needle.size(), 0);
        getNext(needle,next);
        int i = 0;
        int j = 0;
        while (i < haystack.size()) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return i - needle.size() + 1;
            }
            i++;
        }
        return -1;
    }

    void getNext(string needle,vector<int>& next) {
        next[0] = 0;
        int i = 1;
        while (i < needle.size()) {
            int j = next[i - 1];
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];
            }
            if (needle[i] == needle[j]) {
                next[i] = j + 1;
            } else {
                next[i] = 0;
            }
            i++;
        }
    }
};
// @lc code=end

inline void test(){
    Solution s;
// haystack = "aabaabaaf", needle = "aabaaf"
// haystack = "sadbutsad", needle = "sad"
    cout << s.strStr("aabaabaaf","aabaaf") << endl;

    
}