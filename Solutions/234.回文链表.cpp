#include "utils.hpp"
#include <stack>
/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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

    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        ListNode* slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next != nullptr) {
            slow = slow->next;
        }
        ListNode* cur = reverse(slow);
        while (cur != nullptr) {
            if (cur->val != head->val) {
                return false;
            }
            cur = cur->next;
            head = head->next;
        }
        reverse(slow);
        return true;
    }
};
// @lc code=end


inline void test(){
	Solution s;
}