#include "utils.hpp"
#include <vector>
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
// class Solution {
// public:

//     ListNode* reverseSubList(ListNode* head) {
//         if (head->next == nullptr) return head;
//         ListNode* child = reverseSubList(head->next);
//         head->next->next = head;
//         return child;
//     }
//     ListNode* reverseList(ListNode* head) {
//         if (!head) return nullptr;
//         ListNode* res = reverseSubList(head);
//         head->next = nullptr;
//         return res;
//     }
// };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* cur = head;
        while (cur->next) {
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            tmp->next = dummy->next;
            dummy->next = tmp;
        }
        return dummy->next;
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // []
    vector<int> nums = {1,2,3,4,5};
    ListNode* head = create_list(nums);
    printList(s.reverseList(head));
}