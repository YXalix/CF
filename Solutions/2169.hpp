#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=2169 lang=cpp
 *
 * [2169] 得到 0 的操作数
 */

// @lc code=start
class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        if (num1 < num2) swap(num1, num2);
        while (num2 != 0) {
            num1 -= num2;
            if (num1 < num2)
                swap(num1, num2);
            ans++;
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}