#include "utils.hpp"
#include <queue>
#include <utility>
/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int countFreshOrange = 0;
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int k = 0; k < n; k++) {
                if (grid[i][k] == 2) {
                    q.push({i, k});
                } else if (grid[i][k] == 1) {
                    countFreshOrange++;
                }
            }
        }

        int time = 0;
        // four adjacent positions at which the oranged placed will get rotten.
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (countFreshOrange != 0 && !q.empty()) {
            int qsize = q.size();

            for (int i = 0; i<qsize; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(auto d : directions){
                    int nx = x + d.first;
                    int ny = y + d.second;

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        countFreshOrange--;
                        q.push({nx, ny});
                    }
                }
            }
            time++;
        }
        return countFreshOrange == 0 ? time : -1;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}