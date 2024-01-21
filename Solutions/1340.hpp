#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=1340 lang=cpp
 *
 * [1340] 跳跃游戏 V
 */

// @lc code=start
class Solution {
public:
    int maxJumps1(vector<int>& arr, int d) {
        // 建成有向图，然后拓扑排序
        int n = arr.size();
        vector<vector<int>> graph(n,vector<int>());
        vector<int> count(n,0);
        for (int i = 0;i<n;i++){
            for (int j = 1;j<=d;j++){
                int pos1 = i + j;
                if (pos1 >= 0 && pos1 < n){
                    if (arr[pos1] < arr[i]){
                        graph[i].push_back(pos1);
                        count[pos1]++;
                    }else{
                        break;
                    }
                }
            }
            for(int j = 1;j<=d;j++){
                int pos2 = i - j;
                if (pos2 >= 0 && pos2 < n){
                    if (arr[pos2] < arr[i]){
                        graph[i].push_back(pos2);
                        count[pos2]++;
                    }else{
                        break;
                    }
                }
            }
        }
        queue<int> q;
        for (int i = 0;i<n;i++){
            if (count[i] == 0){
                q.push(i);
            }
        }
        int ans = 0;
        while(!q.empty()){
            int len = q.size();
            for (int i = 0;i<len;i++){
                int var = q.front();
                q.pop();
                for (auto item : graph[var]){
                    count[item]--;
                    if (count[item] == 0){
                        q.push(item);
                    }
                }
            }
            ans++;
        }
        return ans;
    }

void maxJumps(vector<int>& arr, int d, int cur, vector<int>& steps, int& ans) {
    if (steps[cur] != -1) return;

    int l = max(0, cur - d);    // 确定左右边界
    int r = min((int)arr.size() - 1, cur + d);

    int step = 0;
    for (int dirction = -1; dirction <= 1; dirction += 2) {    // 方向，往左往右
        for (int i = cur + dirction; i <= r && i >= l; i += dirction) {
            if (arr[cur] <= arr[i]) break;    // 高度超过就结束

            maxJumps(arr, d, i, steps, ans);    // 递归
            step = max(step, steps[i]);
        }
    }

    steps[cur] = step + 1;
    ans = max(ans, steps[cur]);
}

int maxJumps(vector<int>& arr, int d) {
    vector<int> steps(arr.size(), -1);
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        maxJumps(arr, d, i, steps, ans);
    }
    return ans;
}
};
// @lc code=end

inline void test(){
    Solution s;
    // [6,4,14,6,8,13,9,7,10,6,12]
    vector<int> arr{6,4,14,6,8,13,9,7,10,6,12};
    s.maxJumps(arr, 2);
}