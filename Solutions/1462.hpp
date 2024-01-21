#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=1462 lang=cpp
 *
 * [1462] 课程表 IV
 */

// @lc code=start
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses,vector<int>());
        vector<int> count(numCourses,0);
        int parents[101][101] = {0};
        for(int i = 0;i<numCourses;i++){
            parents[i][i] = 1;
        }
        for(auto item : prerequisites){
            graph[item[1]].push_back(item[0]);
            count[item[0]]++;
        }
        queue<int> q;
        for(int i = 0;i<numCourses;++i){
            if (count[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int item = q.front();
            q.pop();
            for (auto i : graph[item]){
                count[i]--;
                for(int j = 0;j<numCourses;j++){
                    parents[i][j] |= parents[item][j];
                }
                if (count[i] == 0){
                    q.push(i);
                }
            }
        }
        int n = queries.size();
        vector<bool> ans(n,false);
        for (int i =0;i<n;i++){
            vector<int> item = queries[i];
            if (parents[item[0]][item[1]]){
                ans[i] = true;
            }
        }
        return ans;
    }


};
// @lc code=end

inline void test(){
    Solution s;
//     2
// [[1,0]]
// [[0,1],[1,0]]
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    vector<vector<int>> queries = {{0,1},{1,0}};
    vector<bool> ans = s.checkIfPrerequisite(numCourses,prerequisites,queries);
    for (auto item : ans){
        cout << item << endl;
    }


}