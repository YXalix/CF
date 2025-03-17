//
// Created by xulzee on 2019/1/23.
//
#ifndef LEETCODEPROJECTCPP_UTILS_H
#define LEETCODEPROJECTCPP_UTILS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <sstream>
#include <sys/_types/_key_t.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(): val(0), next(nullptr), random(nullptr) {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
        random = NULL;
    }

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline ListNode *create_list(vector<int> &nums) {
    if (nums.empty()) {
        return nullptr;
    }
    auto head = new ListNode(nums[0]);
    auto cur = head;
    for (int i = 1; i < nums.size(); ++i) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    return head;
}

inline ListNode *create_list(vector<int> nums) {
    if (nums.empty()) {
        return nullptr;
    }
    auto head = new ListNode(nums[0]);
    auto cur = head;
    for (int i = 1; i < nums.size(); ++i) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    return head;
}

inline void printList(ListNode *head) {
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

inline bool stoi_valid(int& num, string& s) {
    if (s == "null") return false;
    num = stoi(s);
    return true;
}

// create tree by bfs
inline TreeNode *buildTree(vector<string> &nums) {
    if (nums.empty()) return nullptr;
    int val;
    int cur = 0;
    if (!stoi_valid(val, nums[cur])) return nullptr;
    cur++;
    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* p;
    while (!q.empty() && cur < nums.size()) {
        p = q.front();
        q.pop();
        // left
        if (!stoi_valid(val, nums[cur])) p->left = nullptr;
        else {
            p->left = new TreeNode(val);
            q.push(p->left);
        }
        cur++;
        // right
        if (!stoi_valid(val, nums[cur])) p->right = nullptr;
        else {
            p->right = new TreeNode(val);
            q.push(p->right);
        }
        cur++;
    }
    return root;
}

// print tree by bfs
inline void printTree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode *node = q.front();
            q.pop();
            if (node == nullptr) {
                cout << "null ";
                continue;
            }
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
        cout<< endl;
    }
    cout << endl;
}

template <typename a>
inline void printVector(const vector<a> &vec) {
    for (auto &iter : vec) {
        cout << iter << " ";
    }
    cout<<endl;
}

template <typename a>
inline void printHashSet(const unordered_set<a> &vec) {
    for (auto &iter : vec) {
        cout << iter << " ";
    }
    cout<<endl;
}

template <typename a, typename b>
inline void printHashMap(const unordered_map<a,b> &m) {
    for (auto &iter : m) {
        cout << "{" <<iter.first << ", "<<iter.second<<"} ";
    }
    cout<<endl;
}

inline void printIntVector(const vector<int> &vec) {
    for (auto &iter : vec) {
        cout << iter << " ";
    }
}

inline void printCharVector(const vector<char> &vec) {
    for (auto &iter : vec) {
        cout << iter << " ";
    }
}

inline void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

inline void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

inline void SplitByItem(const string &s, const char item, vector<string> &res) {
    string temp;
    stringstream ss;
    ss.str(s);
    while (true) {
        if (!getline(ss, temp, item)) {
            break;
        }
        res.push_back(temp);
    }
}

inline vector<int> SplitByIntItem(const string &s, const char item){
    // item is int
    vector<int>res;
    string temp;
    stringstream ss;
    ss.str(s);
    while (true){
        if (!getline(ss, temp, item)){
            break;
        }
        res.push_back(stoi(temp));
    }
    return res;
}

inline vector<string> SplitByStringItem(const string &s, const char item){
    // item is string
    vector<string>res;
    string temp;
    stringstream ss;
    ss.str(s);
    while (true){
        if (!getline(ss, temp, item)){
            break;
        }
        res.push_back(temp);
    }
    return res;
}

#endif //LEETCODEPROJECTCPP_UTILS_H