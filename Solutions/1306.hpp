#include "utils.hpp"
#include <queue>
#include <vector>
/*
 * @lc app=leetcode.cn id=1306 lang=cpp
 *
 * [1306] 跳跃游戏 III
 */

// @lc code=start
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visit(arr.size(),false);
        return dfs(arr, start, visit);
    }


    bool dfs(vector<int>& arr, int start, vector<bool> &visit){
        if (start < 0 || start >= arr.size() || visit[start]){
            return false;
        }
        if (arr[start] == 0){
            return true;
        }
        visit[start] = true;
        return dfs(arr, start + arr[start], visit) || dfs(arr, start - arr[start], visit);
    }
};
// @lc code=end

inline void test(){
    Solution s;

}