#include "utils.hpp"
#include <cstddef>
#include <unordered_map>
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

// 通过排序，解决重复问题, 通过双指针，将原问题转化为两数之和

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] < 0) {
                break;
            }
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) {
                break;
            }
            int cur = nums[i];
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] + cur == 0) {
                    ans.push_back({cur, nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    j++;
                    k--;
                } else if (nums[j] + nums[k] + cur < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;
// [-1,0,1,2,-1,-4]
    vector<int> nums{-1,0,1,2,-1,-4};
    auto ans = s.threeSum(nums);
    for(auto& vec : ans){
        for(auto& num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
}