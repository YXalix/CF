#include "utils.hpp"
#include <algorithm>
#include <unordered_map>
#include <vector>
/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
 */

// @lc code=start
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> m;
        for (auto i : arr) {
            m[i]++;
        }
        sort(arr.begin(), arr.end(), [](int a, int b) { return abs(a) < abs(b); });
        for (auto i : arr) {
            if (m[i] == 0) {
                continue;
            }
            if (m[i * 2] == 0) {
                return false;
            }
            m[i]--;
            m[i * 2]--;
        }
        return true;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    vector<int> arr = {4,-2,2,-4};
    cout << s.canReorderDoubled(arr) << endl;
}