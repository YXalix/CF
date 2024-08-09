#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool row0 = false;
        bool col0 = false;
        for (int i = 0;i<m;i++) {
            if (matrix[i][0] == 0) {
                col0 = true;
            }
        }
        for (int j = 0;j<n;j++) {
            if (matrix[0][j] == 0) {
                row0 = true;
            }
        }
        for (int i = 1;i<m;i++) {
            for (int j = 1;j<n;j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1;i<m;i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1;j<n;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1;i<n;i++) {
            if (matrix[0][i] == 0) {
                for (int j = 1;j<m;j++){
                    matrix[j][i] = 0;
                }
            }
        }
        if (col0) {
            for (int i = 0;i<m;i++) {
                matrix[i][0] = 0;
            }
        }
        if (row0) {
            for (int j = 0;j<n;j++){
                matrix[0][j] = 0;
            }
        }
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // [[1,2,3,4],[5,0,7,8],[0,10,11,12],[13,14,15,0]]
    vector<vector<int>> matrix = {{1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}};
    for (auto &row : matrix){
        printIntVector(row);
        cout<<endl;
    }
    cout<<endl;
    s.setZeroes(matrix);
    for (auto &row : matrix){
        printIntVector(row);
        cout<<endl;
    }
}