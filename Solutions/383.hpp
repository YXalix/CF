#include "utils.hpp"
#include <unordered_map>
#include <vector>
/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> m(128, 0);
        for (auto& c : magazine) {
            m[c]++;
        }
        for (auto& c : ransomNote) {
            if (m[c] == 0) {
                return false;
            }
            m[c]--;
        }
        return true;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}