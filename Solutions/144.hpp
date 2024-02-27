#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            ans.push_back(node->val);
            if (node->right != nullptr) {
                s.push(node->right);
            }
            if (node->left != nullptr) {
                s.push(node->left);
            }
        }
        return ans;
    }

    vector<int> preorderTraversal1(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> ans;
        ans.push_back(root->val);
        vector<int> left = preorderTraversal1(root->left);
        ans.insert(ans.end(), left.begin(), left.end());
        vector<int> right = preorderTraversal1(root->right);
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}