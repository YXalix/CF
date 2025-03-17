#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* p, stack<TreeNode*>& path) {
        if (root == nullptr) {
            return false;
        }
        path.push(root);
        if (root == p) {
            return true;
        }
        if (dfs(root->left, p, path) || dfs(root->right, p, path)) {
            return true;
        }
        path.pop();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> path_p;
        stack<TreeNode*> path_q;
        dfs(root, q, path_q);
        dfs(root, p, path_p);
        while (path_p.size() > path_q.size()) {
            path_p.pop();
        }
        while (path_q.size() > path_p.size()) {
            path_q.pop();
        }
        while (path_p.top()->val != path_q.top()->val) {
            path_p.pop();
            path_q.pop();
        }
        return path_p.top();
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // [3,5,1,6,2,0,8,null,null,7,4] 5 1
    vector<string> nodes = {"3","5","1","6","2","0","8","null","null","7","4"};
    TreeNode* root = buildTree(nodes);
    printTree(root);
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    cout << s.lowestCommonAncestor(root, p, q)->val << endl;
}