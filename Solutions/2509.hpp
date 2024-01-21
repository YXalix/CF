#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=2509 lang=cpp
 *
 * [2509] 查询树中环的长度
 */

// @lc code=start
class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b) swap(a, b); // 保证 a <= b
            int d = __builtin_clz(a) - __builtin_clz(b);
            b >>= d; // 上跳，和 a 在同一层
            ans[i] = a == b ? d + 1 : d + (32 - __builtin_clz(a ^ b)) * 2 + 1;
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    //3
    //[[5,3],[4,7],[2,3]]
    vector<vector<int>> queries = {{5,3},{4,7},{2,3}};
    auto ans = s.cycleLengthQueries(3,queries);

}