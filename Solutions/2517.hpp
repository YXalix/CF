#include "utils.hpp"
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
/*
 * @lc app=leetcode.cn id=2517 lang=cpp
 *
 * [2517] 礼盒的最大甜蜜度
 */

// @lc code=start
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {

    }
};
// @lc code=end

inline void test(){
    Solution s;
    // 3
    // 2
    // 15
    // [[1,1,1],[1,1,10]]
    // [0,0,0]
    // [1,2,3]
    vector<vector<int>> composition = {{1,1,1},{1,1,10}};
    vector<int> stock = {0,0,0};
    vector<int> cost = {1,2,3};
    cout << s.maxNumberOfAlloys(3, 2, 15, composition, stock, cost) << endl;

}