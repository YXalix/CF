#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        return n + 1;
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // 1,2,3,4,5,6,7,8,9,10,11,12,23,20
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,23,20};
    cout << s.firstMissingPositive(nums) << endl;
}