#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=1140 lang=cpp
 *
 * [1140] 石子游戏 II
 */

// @lc code=start
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int dp[n][n+1];
        memset(dp,0,sizeof(dp));
        int sum = 0;
        for(int i=n-1;i>=0;i--){
            sum += piles[i];
            for(int m=1;m<=n;m++){
                if(i+2*m>=n){
                    dp[i][m] = sum;
                }else{
                    for(int x=1;x<=2*m;x++){
                        dp[i][m] = max(dp[i][m], sum-dp[i+x][max(m,x)]);
                    }
                }
            }
        }
        return dp[0][1];
    }
};
// @lc code=end

inline void test(){
    Solution s;

}