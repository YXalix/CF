#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=795 lang=cpp
 *
 * [795] 区间子数组个数
 */

// @lc code=start
class Solution {
public:
    int arr[100001];
    int location = INT_MAX;
    int pos = 0;
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        long long int ans = 0;
        for (auto i : nums){
            if (i < left){
                arr[pos] = i;
                pos++;
                if (location != INT_MAX){
                    ans += location;
                }
            }
            else if (i >= left && i <= right){
                arr[pos] = i;
                pos++;
                location = pos;
                ans += location;
            }
            else{
                location = INT_MAX;
                pos = 0;
            }
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;
//     [2,1,4,3]
// 2
// 3
    vector<int> nums = {2,1,4,3};
    cout << s.numSubarrayBoundedMax(nums, 2, 3) << endl;

}