#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=829 lang=cpp
 *
 * [829] 连续整数求和
 */

// @lc code=start
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        int i = 1;
        while(1){
            int item = (n - (i-1)*i/2) / i;
            int mod = (n - (i-1)*i/2) % i;
            if (item == 0){
                break;
            }
            if (mod == 0){
                ans++;
            }
            i++;
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    cout << s.consecutiveNumbersSum(15) << endl;
}