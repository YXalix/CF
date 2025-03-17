#include "utils.hpp"
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
/*
 * @lc app=leetcode.cn id=2555 lang=cpp
 *
 * [2555] 两个线段获得的最多奖品
 */

// @lc code=start
class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        if (k * 2 + 1 >= prizePositions[n - 1] - prizePositions[0]) {
            return n;
        }
        vector<int> mx(n + 1, 0);
        int left = 0, right = 0;
        int res = 0;
        for (right = 0; right < n; right++) {
            while (prizePositions[right] - prizePositions[left] > k) {
                left++;
            }
            res = max(res, mx[left] + right - left + 1);
            mx[right + 1] = max(mx[right], right - left + 1);
        }
        return res;
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // prizePositions = [1,2,3,4], k = 0
    // Output: 2
    vector<int> prizePositions = {1, 2, 3, 4};
    int k = 0;
    cout << s.maximizeWin(prizePositions, k) << endl;
}