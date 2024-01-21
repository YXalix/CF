#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]>target) right=mid-1;
            else if(nums[mid]<target) left=mid+1;
            else return mid;
        }
        return -1;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    // [5]
    // 5
    vector<int> nums = {5};
    int target = 5;
    cout << s.search(nums, target) << endl;
}