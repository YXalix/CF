#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    // nums = [3,2,2,3], val = 3
    // 2
    vector<int> nums = {3,2,2,3};
    int val = 3;
    cout << s.removeElement(nums, val) << endl;
}