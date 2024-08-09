#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        if (m == 0) return res;
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        while (true) {
            for (int i = left;i<=right;i++) res.push_back(matrix[top][i]);
            if (++top > bottom) break;
            for (int i = top;i<=bottom;i++) res.push_back(matrix[i][right]);
            if (left > --right) break;
            for (int i = right;i>=left;i--) res.push_back(matrix[bottom][i]);
            if (top > --bottom) break;
            for (int i = bottom;i>=top;i--) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
    }
};
// @lc code=end


inline void test(){
	Solution s;
}