#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int i = 0, j = 0;
        int count = 1;
        int mode = 0;
        while (count <= n * n) {
            ans[i][j] = count;
            count++;
            switch (mode) {
                case 0: {
                    if (j + 1 < n && ans[i][j + 1] == 0) {
                        j++;
                    } else {
                        mode = 1;
                        i++;
                    }
                    break;
                }
                case 1: {
                    if (i + 1 < n && ans[i + 1][j] == 0) {
                        i++;
                    } else {
                        mode = 2;
                        j--;
                    }
                    break;
                }
                case 2: {
                    if (j - 1 >= 0 && ans[i][j - 1] == 0) {
                        j--;
                    } else {
                        mode = 3;
                        i--;
                    }
                    break;
                }
                case 3: {
                    if (i - 1 >= 0 && ans[i - 1][j] == 0) {
                        i--;
                    } else {
                        mode = 0;
                        j++;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    // 3
    // [[1,2,3],[8,9,4],[7,6,5]]
    auto ans = s.generateMatrix(3);
    for (auto& i : ans) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}