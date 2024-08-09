#include "utils.hpp"
#include <algorithm>
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        if (intervals.empty()) return ans;
        ans.push_back(intervals[0]);
        for (auto item : intervals) {
            if (item[0] > ans.back()[1]) {
                ans.push_back(item);
            } else {
                ans.back()[1] = max(ans.back()[1], item[1]);
            }
        }
        return ans;
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // intervals = [[1,3],[2,6],[8,10],[15,18]]
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    for (auto &item : intervals){
        printIntVector(item);
    }
}