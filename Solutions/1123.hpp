#include "utils.hpp"
#include <cstddef>
#include <limits>
#include <stack>
#include <vector>
/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        int maxDepth = 0;
        TreeNode* ans = nullptr;
        dfs(root, 0, maxDepth, ans);
        return ans;
    }

    int dfs(TreeNode* root, int depth, int& maxDepth, TreeNode*& ans){
        if(root == nullptr){
            return depth;
        }
        int leftDepth = dfs(root->left, depth + 1, maxDepth, ans);
        int rightDepth = dfs(root->right, depth + 1, maxDepth, ans);
        if(leftDepth == rightDepth && leftDepth >= maxDepth){
            maxDepth = leftDepth;
            ans = root;
        }
        return max(leftDepth, rightDepth);
    }

        

};
// @lc code=end

inline void test(){
    Solution s;

}