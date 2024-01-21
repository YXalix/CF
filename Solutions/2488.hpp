#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=2488 lang=cpp
 *
 * [2488] 统计中位数为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int,int> mp{{0, 1}};
        int pos = 0;
        for(int i = 0;i<n;i++){
            if (nums[i] == k){
                pos = i;
                break;
            }
        }
        int x = 0;
        for (int i = pos-1;i>=0;i--){
            if (nums[i] < k){
                x++;
            }else if (nums[i] > k){
                x--;
            }
            mp[x]++;
        }
        ans = mp[0] + mp[-1];
        x = 0;
        for (int i = pos+1;i<n;i++){
            if (nums[i] < k){
                x--;
            }else if (nums[i] > k){
                x++;
            }
            ans += mp[x] + mp[x-1];
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    // [3,2,1,4,5]
    // 4
    vector<int> nums = {3,2,1,4,5};
    auto ans = s.countSubarrays(nums,4);

}