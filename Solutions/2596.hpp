#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=2596 lang=cpp
 *
 * [2596] 检查骑士巡视方案
 */

// @lc code=start
class Solution {
public:

    struct node{
        int x;
        int y;

        node(int x,int y){
            x = x;
            y=y;
        }
    };

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<node> step(n*n,node(0,0));
        for (int i = 0;i<n;i++){
            for (int j = 0;j<n;j++){
                int val = grid[i][j];
                step[val].x = i;
                step[val].y = j;
            }
        }
        int len = n*n;
        if (step[0].x != 0 || step[0].y != 0){
            return false;
        }
        for (int i = 1;i<len;i++){
            int x = abs(step[i-1].x - step[i].x);
            int y = abs(step[i-1].y - step[i].y);
            if (x * y != 2){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}