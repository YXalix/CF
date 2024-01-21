#include "utils.hpp"
#include <stack>
/*
 * @lc app=leetcode.cn id=1028 lang=cpp
 *
 * [1028] 从先序遍历还原二叉树
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
    TreeNode* recoverFromPreorder(string traversal) {
        TreeNode* root;
        int i = 0;
        while (i < traversal.size() && traversal[i] != '-'){
            i++;
        }
        root = new TreeNode(stoi(traversal.substr(0,i)));
        stack<TreeNode*> s;
        s.push(root);
        while (i < traversal.size()){
            int depth = 0;
            int j = i;
            while (j < traversal.size() && traversal[j] == '-'){
                depth++;
                j++;
            }
            i = j;
            while (i < traversal.size() && traversal[i] != '-'){
                i++;
            }
            TreeNode* node = new TreeNode(stoi(traversal.substr(j,i-j)));
            while (s.size() > depth){
                s.pop();
            }
            if (s.top()->left == nullptr){
                s.top()->left = node;
            }else{
                s.top()->right = node;
            }
            s.push(node);
        }
        return root;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}