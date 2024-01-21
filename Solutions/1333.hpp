#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=1333 lang=cpp
 *
 * [1333] 餐厅过滤器
 */

// @lc code=start
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        sort(restaurants.begin(), restaurants.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]) {
                return a[0] > b[0];
            } else {
                return a[1] > b[1];
            }
        });
        vector<int> res;
        for (auto& r : restaurants) {
            if (veganFriendly == 1 && r[2] == 0) {
                continue;
            }
            if (r[3] > maxPrice) {
                continue;
            }
            if (r[4] > maxDistance) {
                continue;
            }
            res.push_back(r[0]);
        }
        return res;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}