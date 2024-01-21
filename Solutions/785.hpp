#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0);
        for(int i = 0;i<graph.size();i++){
            if(color[i] == 0 && !dfs(graph, color, i, 1)){
                return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int c){
        if(color[node] != 0){
            return color[node] == c;
        }
        color[node] = c;
        for(int neighbor : graph[node]){
            if(!dfs(graph, color, neighbor, -c)){
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