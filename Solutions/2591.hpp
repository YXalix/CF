#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=2591 lang=cpp
 *
 * [2591] 将钱分给最多的儿童
 */

// @lc code=start
class Solution {
public:
    int distMoney(int money, int children) {
        money  = money - children;
        if (money < 0) return -1;
        int count = money / 7;
        count = min(count,children);
        int l = money - count * 7;
        if (count == children && l > 0) return children-1;
        else if (count == children - 1 && l == 3){
            return count-1;
        }else{
            return count;
        }
    }
};
// @lc code=end

inline void test(){
    Solution s;

}