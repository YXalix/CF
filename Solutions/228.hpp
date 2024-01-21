#include "utils.hpp"
#include <string>
#include <utility>
#include <vector>
/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        queue<pair<int, int>> q;
        if (nums.size() == 0){
            return vector<string> {};
        }
        int start = nums[0];
        for(int i = 1;i< nums.size();i++){
            if(nums[i-1]+ 1 != nums[i]){
                q.push({start,nums[i-1]});
                start = nums[i];
            }
        }
        q.push({start,nums[nums.size()-1]});
        vector<string> ans;
        int len = q.size();
        for (int i = 0; i< len; i++) {
            auto temp = q.front();
            q.pop();
            if (temp.first != temp.second){
                ans.push_back(to_string(temp.first) + "->" + to_string(temp.second));
            }
            else {
                ans.push_back(to_string(temp.first));
            }
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}