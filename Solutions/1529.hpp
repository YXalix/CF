#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=1529 lang=cpp
 *
 * [1529] 最少的后缀翻转次数
 */

// @lc code=start
class Solution {
public:
    int minFlips(string target) {
        target = "0" + target;
        int res = 0;
        for (int i = 1;i<target.size();++i){
            if (target[i] != target[i-1])
                ++res;
        }
        return res;
    }
};
// @lc code=end

inline void test(){
    Solution s;
}