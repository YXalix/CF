#include "utils.hpp"
#include <unordered_map>
#include <vector>
/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int res = 0;
    unordered_map<long long int, long long int> cnt;
    void dfs(TreeNode* root, long long int targetSum, long long int cur = 0) {
        if (root == nullptr) {
            return;
        }
        cur += root->val;
        if (cnt.contains(cur - targetSum)) {
            res += cnt[cur - targetSum];
        }
        cnt[cur]++;
        dfs(root->left, targetSum, cur);
        dfs(root->right, targetSum, cur);
        cnt[cur]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }
        cnt.insert({0,1});
        dfs(root, targetSum);
        return res;
    }
};
// @lc code=end
inline void test(){
	Solution s;
    // [5,4,8,11,null,13,4,7,2,null,null,5,1]
    vector<string> nodes = {"5","4","8","11","null","13","4","7","2","null","null","5","1"};
    TreeNode* root = buildTree(nodes);
    printTree(root);
    cout << s.pathSum(root, 22) << endl;
}