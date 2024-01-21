#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=2608 lang=cpp
 *
 * [2608] 图中的最短环
 */

// @lc code=start
class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : g[u]) {
                    if (dist[v] == INT_MAX) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    } else if (dist[v] >= dist[u]) {
                        ans = min(ans, dist[u] + dist[v] + 1);
                    }
                    
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}