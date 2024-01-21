#include "utils.hpp"
#include <unordered_map>
/*
 * @lc app=leetcode.cn id=873 lang=cpp
 *
 * [873] 最长的斐波那契子序列的长度
 */

// @lc code=start
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int , int> m;
        for (int i = 0;i<n;i++){
            m[arr[i]] = i;
        }
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for (int i = 0;i<n;i++){
            for (int j = i - 1; j >= 0 && arr[j] * 2 > arr[i]; j--){
                int k = -1;
                int var = arr[i]- arr[j];
                if (m.count(var)){
                    k = m[var];
                }
                if (k >= 0) {
                    dp[j][i] = max(dp[k][j] + 1, 3);
                }
                ans = max(ans,dp[j][i]);
            }
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}