#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        for(int i = 1;i<=m;i++){
            for (int j = 1;j<=n;j++){
                if (obstacleGrid[i-1][j-1] == 0){
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

inline void test(){
    Solution s;
    // [[0,0,0],[0,1,0],[0,0,0]]
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;

}