#include "utils.hpp"
#include <queue>
#include <variant>
#include <vector>
/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       vector<vector<int>> graph(501);
       vector<int> visited(501,0);
       buildGraph(root, graph);
       queue<int> q;
       q.push(target->val);
       visited[target->val] = 1;
       for (int i = 0;i<k;i++){
        int len = q.size();
        for(int j = 0;j<len;j++){
            int item = q.front();
            q.pop();
            for(auto node : graph[item]){
                if (visited[node] == 0) {
                    q.push(node);
                    visited[node] = 1;
                }
            }
        }
       }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
       return ans;
    }



    void buildGraph(TreeNode* root, vector<vector<int>>& graph){
        if (root == nullptr) return;
        if (root->left != nullptr){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            buildGraph(root->left, graph);
        }
        if (root->right != nullptr){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            buildGraph(root->right, graph);
        }
        return;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}