#include "utils.hpp"
#include <unordered_map>
/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    unordered_map<int, int> map;
    int pre = 0;
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if (l >= r) return nullptr;
        int val = preorder[pre];
        TreeNode* root = new TreeNode(val);
        int mid = map[val];
        pre++;
        root->left = dfs(preorder, inorder, l, mid);
        root->right = dfs(preorder, inorder, mid+1, r);
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        return dfs(preorder, inorder, 0, inorder.size());
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = s.buildTree(preorder, inorder);
    printTree(root);
}