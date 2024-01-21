#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> ans;
        vector<int> node(n,0);
        vector<vector<int>> g(n,vector<int>());
        for (auto item : prerequisites){
            node[item[0]]++;
            g[item[1]].push_back(item[0]);
        }
        queue<int> q;
        for (int i = 0;i<n;i++){
            if (node[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int item = q.front();
            q.pop();
            count++;
            ans.push_back(item);
            for (auto i : g[item]){
                node[i]--;
                if (node[i] == 0){
                    q.push(i);
                }
            }
        }
        if (count == numCourses){
            return ans;
        }
        return vector<int>();
    }
};
// @lc code=end

inline void test(){
    Solution s;

}