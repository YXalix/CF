#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=1406 lang=cpp
 *
 * [1406] 石子游戏 III
 */

// @lc code=start
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> suffix_sum(n,0);
        suffix_sum[n-1] = stoneValue[n-1];
        for (int i = n-2;i >= 0;i--){
            suffix_sum[i] = suffix_sum[i+1] + stoneValue[i];
        }

        vector<int> f(n+1,0);

        for (int i = n-1;i>=0;i--){
            int bestj = f[i + 1];
            for (int j = i + 2; j <= i + 3 && j <= n; ++j) {
                bestj = min(bestj, f[j]);
            }
            f[i] = suffix_sum[i] - bestj;
        }
        if (f[0] * 2 > suffix_sum[0]){
            return "Alice";
        } else if (f[0] * 2 == suffix_sum[0]){
            return "Tie";
        } else {
            return "Bob";
        }
    }
};
// @lc code=end

inline void test(){
    Solution s;

}