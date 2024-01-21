#include "utils.hpp"
#include <algorithm>
#include <climits>
#include <vector>
/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n, 0);
        for(int i = 0;i<n;i++){
            dp[i] = matrix[0][i];
        }
        for(int i = 1;i<n;i++){
            vector<int> tmp(n, 0);
            for(int j = 0;j<n;j++){
                tmp[j] = dp[j];
                if(j>0){
                    tmp[j] = min(dp[j-1] + matrix[i][j], tmp[j]);
                }
                tmp[j] = min(dp[j] + matrix[i][j], tmp[j]);
                if(j<n-1){
                    tmp[j] = min(dp[j+1] + matrix[i][j], tmp[j]);
                }
            }
            dp = tmp;
        }
        int ans = INT_MAX;
        for (int i = 0; i<n; i++) {
            ans = min(ans,dp[i]);
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    vector<vector<int>> matrix = {{17,86},{1,-44}};
    cout << s.minFallingPathSum(matrix) << endl;
}