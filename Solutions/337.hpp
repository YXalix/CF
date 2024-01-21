#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode* root) {
        vector<int> a(2,0);
        dfs(root, a);
        return max(a[0], a[1]);
    }


    void dfs(TreeNode* root, vector<int> &a){
        if(root == nullptr) return;
        vector<int> a_l(2,0);
        vector<int> a_r(2,0);
        dfs(root->left, a_l);
        dfs(root->right, a_r);
        a[0] = a_l[1] + a_r[1] + root->val;
        a[1] = max(a_l[0], a_l[1]) + max(a_r[0], a_r[1]);
    }

};
// @lc code=end

inline void test(){
    Solution s;
    // [2,1,3,null,4]
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    cout << s.rob(root) << endl;
}