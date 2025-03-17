#include "utils.hpp"
#include <queue>
#include <vector>
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            vector<int> lvs;
            for (int i = 0;i<len;i++) {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp) {
                    lvs.push_back(tmp->val);
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
            }
            if (lvs.empty()) continue;
            res.push_back(lvs);
        }
        return res;
    }
};
// @lc code=end


inline void test(){
	Solution s;
}