#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=1444 lang=cpp
 *
 * [1444] 切披萨的方案数
 */

// @lc code=start
// 二维前缀和模板（'A' 的 ASCII 码最低位为 1，'.' 的 ASCII 码最低位为 0）
class MatrixSum {
private:
    vector<vector<int>> sum;

public:
    MatrixSum(vector<string> &matrix) {
        int m = matrix.size(), n = matrix[0].length();
        sum = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + (matrix[i][j] & 1);
            }
        }
    }

    // 返回左上角在 (r1,c1) 右下角在 (r2-1,c2-1) 的子矩阵元素和（类似前缀和的左闭右开）
    int query(int r1, int c1, int r2, int c2) {
        return sum[r2][c2] - sum[r2][c1] - sum[r1][c2] + sum[r1][c1];
    }
};

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int MOD = 1e9 + 7;
        MatrixSum ms(pizza);
        int m = pizza.size(), n = pizza[0].length();
        function<int(int, int, int)> dfs = [&](int c, int i, int j) -> int {
            if (c == 0) // 递归边界：无法再切了
                return ms.query(i, j, m, n) ? 1 : 0;
            int res = 0;
            for (int j2 = j + 1; j2 < n; j2++) // 垂直切
                if (ms.query(i, j, m, j2)) // 有苹果
                    res = (res + dfs(c - 1, i, j2)) % MOD;
            for (int i2 = i + 1; i2 < m; i2++) // 水平切
                if (ms.query(i, j, i2, n)) // 有苹果
                    res = (res + dfs(c - 1, i2, j)) % MOD;
            return res;
        };
        return dfs(k - 1, 0, 0);
    }
};
// @lc code=end

inline void test(){
    Solution s;

}