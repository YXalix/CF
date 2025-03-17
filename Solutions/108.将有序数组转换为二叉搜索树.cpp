#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return build(nums, 0, nums.size());
    }

    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l==r) return nullptr;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, l, mid);
        root->right = build(nums, mid+1, r);
        return root;
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // nums = [-10,-3,0,5,9]
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode* root = s.sortedArrayToBST(nums);
    // bfs output: [0,-3,9,-10,null,5]
    printTree(root);
}