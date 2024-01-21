#include "utils.hpp"
#include <queue>
#include <vector>
/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
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
            for (auto i : g[item]){
                node[i]--;
                if (node[i] == 0){
                    q.push(i);
                }
            }
        }
        if (count == numCourses){
            return true;
        }
        return false;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    //[[1,4],[2,4],[3,1],[3,2]]
    vector<vector<int>> prerequisites = {{1,4},{2,4},{3,1},{3,2}};
    cout << s.canFinish(5,prerequisites) << endl;

}