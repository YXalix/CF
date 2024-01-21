#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto res = reverseList(head->next);
        auto next = head->next;
        next->next = head;
        head->next = nullptr;
        return res;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    // head = [1,2,3,4,5]
    // 输出：[5,4,3,2,1]
    auto nums = vector<int>{1,2,3,4,5};
    auto head = create_list(nums);
    auto res = s.reverseList(head);
    while (res != nullptr) {
        cout << res->val << endl;
        res = res->next;
    }
}