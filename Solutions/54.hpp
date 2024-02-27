#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:

    /*
        定义四个方向的bound
        left_bound, right_bound, top_bound, bottom_bound
    */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m == 0) return res;
        int n = matrix[0].size();
        int left_bound = 0, right_bound = n - 1, top_bound = 0, bottom_bound = m - 1;
        while (res.size() < m * n) {
            if (bottom_bound >= top_bound) {
                for (int i = left_bound; i <= right_bound; i++) {
                    res.push_back(matrix[top_bound][i]);
                }
                top_bound++;
            }
            if (right_bound >= left_bound) {
                for (int i = top_bound; i <= bottom_bound; i++) {
                    res.push_back(matrix[i][right_bound]);
                }
                right_bound--;
            }
            if (bottom_bound >= top_bound) {
                for (int i = right_bound; i >= left_bound; i--) {
                    res.push_back(matrix[bottom_bound][i]);
                }
                bottom_bound--;
            }
            if (right_bound >= left_bound) {
                for (int i = bottom_bound; i >= top_bound; i--) {
                    res.push_back(matrix[i][left_bound]);
                }
                left_bound++;
            }
        }
        return res;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    // [[1,2,3,4],[5,6,7,8],[9,10,11,12]]

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    printIntVector(s.spiralOrder(matrix));
}