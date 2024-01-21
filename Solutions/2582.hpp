#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=2582 lang=cpp
 *
 * [2582] 递枕头
 */

// @lc code=start
class Solution {
public:
    int passThePillow(int n, int time) {
       int it = time / (n-1);
        int res = time % (n-1);
        if (it % 2 == 0) {
            return res + 1;
        } else {
            return n - res;
        }
    }
};
// @lc code=end
inline void test(){
    Solution s;

}