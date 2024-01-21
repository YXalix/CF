#include "utils.hpp"
#include <climits>
/*
 * @lc app=leetcode.cn id=939 lang=cpp
 *
 * [939] 最小面积矩形
 */

// @lc code=start
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans = INT_MAX;
        unordered_map<int, unordered_set<int>> x2y;
        for(auto point : points){
            x2y[point[0]].insert(point[1]);
        }
        int n = points.size();
        sort(points.begin(),points.end());
        for (int i = 0;i<n;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i+1;j<n;j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x2 != x1 && y2 != y1){
                    if (x2y[x1].count(y2) && x2y[x2].count(y1)){
                        ans = min(ans, abs(x2-x1)*abs(y2-y1));
                    }
                }
            }
        }
        if (ans == INT_MAX) ans = 0;
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}