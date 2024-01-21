#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 */

// @lc code=start
class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1;i<=n;++i){
            if (isGood(i)) ++ans;
        }
        return ans;
    }

    bool isGood(int n){
        bool flag = false;
        while (n){
            int t = n % 10;
            if (t == 3 || t == 4 || t == 7) return false;
            if (t == 2 || t == 5 || t == 6 || t == 9) flag = true;
            n /= 10;
        }
        return flag;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}