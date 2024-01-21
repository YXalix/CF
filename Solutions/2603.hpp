#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=2603 lang=cpp
 *
 * [2603] 收集树中金币
 */

// @lc code=start
class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
       int n = coins.size();
       vector<vector<int>> g(n);
        vector<int> deg(n,0);
        for(auto &e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }

        int left_node = n;

        vector<int> q;
        for (int i = 0; i < n; i++){
            if(deg[i] == 1 && coins[i] == 0){
                q.push_back(i);
            }
        }
        while (!q.empty()){
            int u = q.back();
            q.pop_back();
            left_node--;
            for(int v : g[u]){
                if(--deg[v] == 1 && coins[v] == 0){
                    q.push_back(v);
                }
            }
        }

        for (int i = 0; i < n; i++){
            if(deg[i] == 1 && coins[i] == 1){
                q.push_back(i);
            }
        }
        left_node -= q.size();
        for (int x : q){
            for (int y : g[x]){
                if(--deg[y] == 1){
                    left_node--;
                }
            }
        }
        return max((left_node-1) * 2, 0);
    }
};
// @lc code=end

inline void test(){
    Solution s;

}