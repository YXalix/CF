#include "utils.hpp"
#include <array>
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0;i<n;i++) {
            for (int j = i+1;j<n;j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<n / 2;j++) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    s.rotate(matrix);
    for (auto &row : matrix) {
        printIntVector(row);
    }
}