#include "utils.hpp"
#include <queue>
#include <vector>
/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution {
private:
    bool** graph;
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1) {
            return {0};
        }

        vector<int> ans;
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        // create graph
        for(vector<int> &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if(indegree[i] == 1){
                q.push(i);
                indegree[i]--;
            }
        }

        while (!q.empty()) {
            int s = q.size();
            ans.clear();
            for(int i = 0;i<s;i++){
                int curr = q.front();q.pop();
                ans.push_back(curr);
                for(auto child : adj[curr]){
                    indegree[child]--;
                    if (indegree[child] == 1) {
                        q.push(child);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    int n =6;
    vector<vector<int>> edges{{3,0},{3,1},{3,2},{3,4},{5,4}};
    Solution s;
    printIntVector(s.findMinHeightTrees(n, edges));
}