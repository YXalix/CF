#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=878 lang=cpp
 *
 * [878] 第 N 个神奇数字
 */

// @lc code=start
class Solution {
    const long MOD = 1e9 + 7;
public:
    int nthMagicalNumber(int n, int a, int b) {
        long lcm = lcmf(a, b);
        long left = 0, right = (long) min(a, b) * n; // 开区间 (left, right)
        while (left + 1 < right) { // 开区间不为空
            long mid = left + (right - left) / 2;
            if (mid / a + mid / b - mid / lcm >= n)
                right = mid; // 范围缩小到 (left, mid)
            else
                left = mid; // 范围缩小到 (mid, right)
        }
        return right % MOD;
    }

    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long lcmf(long a, long b) {
        return a * b / gcd(a, b);
    }

};
// @lc code=end

inline void test(){
    Solution s;
    cout << s.nthMagicalNumber(5, 2, 4) << endl;

}