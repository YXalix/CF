#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy{};
        dummy.next = head;
        ListNode* cur = &dummy;
        while (cur->next && cur->next->next) {
            ListNode* p = cur->next;
            ListNode* q = p->next;
            cur->next = q;
            p->next = q->next;
            q->next = p;
            cur = cur->next->next;
        }
        return dummy.next;
    }
};
// @lc code=end


inline void test(){
	Solution s;
}