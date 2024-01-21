#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
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
    const int inf = INT_MAX-1;
    struct SubTree{
        bool isBST;
        int minValue;
        int maxValue;
        int sumValue;
        SubTree(bool isBST, int minValue, int maxValue, int sumValue):isBST(isBST), minValue(minValue), maxValue(maxValue), sumValue(sumValue) {}
    };

    int ans = -INT32_MAX;
    int maxSumBST(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }

    SubTree dfs(TreeNode* root){
        if (root == nullptr){
            return SubTree(true,inf, -inf,0);
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if (left.isBST && right.isBST && root->val > left.maxValue && root->val < right.minValue){
            int sumValue = left.sumValue+ right.sumValue + root->val;
            ans = max(sumValue, ans);
            return SubTree(true,min(left.minValue, root->val),max(root->val, right.maxValue),sumValue);
        }else{
            return SubTree(false,0,0,0);
        }
    }
};
// @lc code=end

inline void test(){
    Solution s;
    // [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->left->left->left = nullptr;
    root->left->left->right = nullptr;
    root->left->right->left = nullptr;
    root->left->right->right = nullptr;
    root->right->left->left = nullptr;
    root->right->left->right = nullptr;
    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(6);
    cout << s.maxSumBST(root) << endl;
    

}