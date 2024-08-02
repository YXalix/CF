#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=2642 lang=cpp
 *
 * [2642] 设计可以求最短路径的图类
 */

// @lc code=start
class Graph {
    vector<vector<pair<int, int>>> g; // 邻接表
public:
    Graph(int n, vector<vector<int>>& edges): g(n) {
        for (auto &e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
        }
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        int n = g.size();
        vector<int> dis(n, INT_MAX);
        dis[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, node1});
        while (!pq.empty()) {
            auto [d, x] = pq.top();
            pq.pop();
            if (x == node2) {
                return d;
            }
            if (d > dis[x]) {
                continue;
            }
            for (auto &[y, w] : g[x]) {
                if (d + w < dis[y]) {
                    dis[y] = d + w;
                    pq.push({dis[y], y});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
// @lc code=end

inline void test(){
    Solution s;

}