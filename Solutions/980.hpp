#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=980 lang=cpp
 *
 * [980] 不同路径 III
 */

// @lc code=start
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int start_x = 0;
        int start_y = 0;
        int end_x = 0;
        int end_y = 0;
        int zero_num = 0;
        for (int i = 0;i<m;i++){
            for (int j = 0;j<n;j++){
                if (grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                }
                else if (grid[i][j] == 2){
                    end_x = i;
                    end_y = j;
                }
                else if (grid[i][j] == 0){
                    zero_num++;
                }
            }
        }
        int ans = 0;
        ans = dfs(grid,start_x,start_y,end_x,end_y,zero_num);
        return ans;
    }



    int dfs(vector<vector<int>>& grid, int start_x,int start_y,int end_x, int end_y, int zero_num){
        // print grid
        for (auto i : grid){
            for (auto j : i){
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
        if (start_x == end_x && start_y == end_y){
            if (zero_num < 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        int ans = 0;
        grid[start_x][start_y] = -1;
        if (start_x - 1 >= 0 && grid[start_x-1][start_y] != -1){
            ans += dfs(grid,start_x-1,start_y,end_x,end_y,zero_num-1);
        }
        if (start_x + 1 < grid.size() && grid[start_x+1][start_y] != -1){
            ans += dfs(grid,start_x+1,start_y,end_x,end_y,zero_num-1);
        }
        if (start_y - 1 >= 0 && grid[start_x][start_y-1] != -1){
            ans += dfs(grid,start_x,start_y-1,end_x,end_y,zero_num-1);
        }
        if (start_y + 1 < grid[0].size() && grid[start_x][start_y+1] != -1){
            ans += dfs(grid,start_x,start_y+1,end_x,end_y,zero_num-1);
        }
        grid[start_x][start_y] = 0;
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    // [[0,1],[2,0]]
    vector<vector<int>> grid = {{0,1},{2,0}};
    cout << s.uniquePathsIII(grid) << endl;

}