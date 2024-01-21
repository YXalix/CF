#include "utils.hpp"
#include <algorithm>
#include <climits>
#include <vector>
/*
 * @lc app=leetcode.cn id=2560 lang=cpp
 *
 * [2560] 打家劫舍 IV
 */

// @lc code=start
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = *max_element(nums.begin(),nums.end());
        while (left + 1 < right){
            int mid = (left + right) / 2;
            if(check(nums, mid, k)){
                right = mid;
            }else{
                left = mid;
            }
        }
        return right;
    }

    bool check(vector<int>& nums, int mid, int k){
        int f0 = 0;
        int f1 = 0;
        for(int x : nums){
            if (x > mid){
                f0 = f1;
            }else{
                int tmp = f1;
                f1 = max(f1, f0 + 1);
                f0 = tmp;
            }
        }
        return f1 >= k;
    }

};
// @lc code=end

inline void test(){
    Solution s;
    // [2,3,5,9]
    vector<int> nums = {2,3,5,9};
    cout << s.minCapability(nums,2) << endl;

}