#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=1222 lang=cpp
 *
 * [1222] 可以攻击国王的皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        vector<vector<int>> board(8,vector<int>(8,0));
        for (auto item : queens){
            board[item[0]][item[1]] = 1;
        }
        int x = king[0];
        int y = king[1];
        for (int i = x;i<8;i++){
            if (board[i][y] == 1){
                ans.push_back({i,y});
                break;
            }
        }
        for (int i = x;i>=0;i--){
            if (board[i][y] == 1){
                ans.push_back({i,y});
                break;
            }
        }
        for (int i = y;i<8;i++){
            if (board[x][i] == 1){
                ans.push_back({x,i});
                break;
            }
        }
        for (int i = y;i>=0;i--){
            if (board[x][i] == 1){
                ans.push_back({x,i});
                break;
            }
        }
        for (int i = x,j = y;i<8 && j<8;i++,j++){
            if (board[i][j] == 1){
                ans.push_back({i,j});
                break;
            }
        }
        for (int i = x,j = y;i>=0 && j>=0;i--,j--){
            if (board[i][j] == 1){
                ans.push_back({i,j});
                break;
            }
        }
        for (int i = x,j = y;i<8 && j>=0;i++,j--){
            if (board[i][j] == 1){
                ans.push_back({i,j});
                break;
            }
        }
        for (int i = x,j = y;i>=0 && j<8;i--,j++){
            if (board[i][j] == 1){
                ans.push_back({i,j});
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}