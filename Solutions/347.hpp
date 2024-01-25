#include "utils.hpp"
#include <functional>
#include <queue>
#include <utility>
#include <vector>
/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pq(cmp);
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
        }
        for (auto it = um.begin(); it != um.end(); it++) {
            if (pq.size() < k) {
                pq.push(*it);
            } else {
                if (it->second > pq.top().second) {
                    pq.pop();
                    pq.push(*it);
                }
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;
// 输入: nums = [1,1,1,2,2,3], k = 2
// 输出: [1,2]
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    printIntVector(s.topKFrequent(nums, k));
}