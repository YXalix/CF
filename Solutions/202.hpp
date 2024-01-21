#include "utils.hpp"
#include <unordered_set>
/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<long long int> s;
        while (n != 1) {
            if (s.count(n)) {
                return false;
            }
            s.insert(n);
            n = getNext(n);
        }
        return true;
    }

    long long int getNext(int n) {
        long long int ans = 0;
        while (n) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}