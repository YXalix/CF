#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(graph, 0, path, ans);
        return ans;
    }

    void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& ans){
        path.push_back(node);
        if(node == graph.size() - 1){
            ans.push_back(path);
        }else{
            for(int nextNode : graph[node]){
                dfs(graph, nextNode, path, ans);
            }
        }
        path.pop_back();
    }
};
// @lc code=end

inline void test(){
    Solution s;

}