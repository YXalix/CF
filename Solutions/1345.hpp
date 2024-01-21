#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=1345 lang=cpp
 *
 * [1345] 跳跃游戏 IV
 */

// @lc code=start
class Solution {
public:
    int n;
    unordered_map<int,vector<int>> m;
    int minJumps(vector<int>& arr) {
        n = arr.size();
        vector<bool> visit(n,false);
        for(int i = 0;i<n;i++){
            m[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        visit[0];
        int ans = 0;
        while(!q.empty()){
            int len = q.size();
            for (int i = 0;i<len;i++){
                int pos = q.front();
                q.pop();
                int var = arr[pos];
                if (pos == n-1){
                    return ans;
                }
                if (pos > 0 && visit[pos-1] == false){
                    q.push(pos-1);
                    visit[pos-1] = true;
                }
                if ( pos < n-1 && visit[pos+1] == false){
                    q.push(pos+1);
                    visit[pos+1] = true;
                }
                if (m.count(var) ){
                    for (auto i : m[var]){
                        if (visit[i] == false){
                            q.push(i);
                            visit[i] = true;
                        }
                    }
                    m.erase(var);
                }
            }
            ans++;
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    // [100,-23,-23,404,100,23,23,23,3,404]
    vector<int> arr{100,-23,-23,404,100,23,23,23,3,404};
    s.minJumps(arr);
}