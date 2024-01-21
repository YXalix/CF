#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 3; i++) {

            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if ((long)nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] < target) {
                continue;
            }
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            long cur = nums[i];
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if (cur + nums[j] + nums[nums.size() - 1] + nums[nums.size() - 2] < (long)target) {
                    continue;
                }
                if (cur + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                long cur2 = nums[j];
                int k = j + 1, l = nums.size() - 1;
                while (k < l) {
                    if (cur + cur2 + nums[k] + nums[l] == target) {
                        ans.push_back({(int)cur, (int)cur2, nums[k], nums[l]});
                        while (k < l && nums[k] == nums[k + 1]) {
                            k++;
                        }
                        while (k < l && nums[l] == nums[l - 1]) {
                            l--;
                        }
                        k++;
                        l--;
                    } else if (cur + cur2 + nums[k] + nums[l] < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}