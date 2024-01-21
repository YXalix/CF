#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=1319 lang=cpp
 *
 * [1319] 连通网络的操作次数
 */

// @lc code=start
class Solution {
public:
    int res;
    int find(vector<int> &node,int i){
        int x = i;
        while(node[x] != x){
            x = node[x];
        }
        while(node[i] != i){
            i = node[i];
            node[i] = x;
        }
        return x;
    }

    void munion(vector<int> &node,int a,int b){
        int x = find(node, b);
        int y = find(node,a);
        if (x == y) return;
        node[x] = y;
        res--;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        res = n;
        int m = connections.size();
        if (m < n-1) return -1;
        vector<int> node(n,0);
        for(int i = 0;i<n;i++){
            node[i] = i;
        }
        for(auto i : connections){
            if(find(node,i[0]) != find(node, i[1])){
                munion(node, i[0], i[1]);
            }
        }
        return res-1;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}