#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
    二分 + 反悔贪心
    快速复习是最重要的,
    判断是否可以在第second秒标记所有的点
    什么情况下可以快速复习呢?
        1. 首先对于每一门课来说, 要么快速复习, 要么全部慢速复习
        2. 所以能快速复习, 就快速复习
    什么情况下不能快速复习呢?
        1. 如果当前课程快速复习, 那么后面就没有cnt来进行考试了
    1. 从后往前遍历, 如果当前点是需要标记的点, 则将其加入到优先队列中

*/

class Solution {
public:
    long long total = 0;

    bool check(vector<int>& nums, vector<int>& changeIndices, int second, vector<int>& first_t){
        priority_queue<int, vector<int>, greater<>> pq;
        int cnt = 0;

        int slow = total;
        for (int t = second; t >= 0; t--){
            int index = changeIndices[t] - 1;
            int v = nums[index];
            if (v <= 1 || first_t[index] != t) {
                cnt++; // 留给左边，用来快速复习/考试
                continue;
            }
            if (cnt == 0) {
                if (pq.empty() || v <= pq.top()) {
                    cnt++; // 留给左边，用来快速复习/考试
                    continue;
                }
                slow += pq.top() + 1;
                pq.pop();
                cnt += 2; // 反悔：一天快速复习，一天考试
            }
            slow -= v + 1;
            cnt--; // 快速复习，然后消耗一天来考试
            pq.push(v);
        }
        return cnt >= slow; // 剩余天数不能慢速复习+考试
    }

    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();
        total = n + accumulate(nums.begin(), nums.end(), 0LL);
        vector<int> first_t(n, -1);
        for (int i = m - 1; i >= 0; i--){
            first_t[changeIndices[i]] = i;
        }


        int left = n, right = m;
        int ans = -1;
        while(left < right){
            int mid = (left + right) / 2;
            if(check(nums, changeIndices, mid, first_t)){
                ans = mid;
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    // 输入：nums = [3,2,3], changeIndices = [1,3,2,2,2,2,3]
    // 输出：6

    vector<int> nums = {3, 2, 3};
    vector<int> changeIndices = {1, 3, 2, 2, 2, 2, 3};
    cout << s.earliestSecondToMarkIndices(nums, changeIndices) << endl;
}