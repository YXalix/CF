#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums) {
            sum += i;
        }
        int cur = 0;
        for (int i = 0;i<nums.size();i++) {
            if (cur * 2 == sum - nums[i]) {
                return i;
            }
            cur += nums[i];
        }
        return -1;
    }
};
// @lc code=end

inline void test(){
	Solution s;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout<<s.pivotIndex(nums)<<endl;
}