#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }
        ListNode dummy{};
        dummy.next = head;
        cur = &dummy;
        for (int i = k;i<=n;i+=k) {
            ListNode* pre = cur;
            cur = cur->next;
            for (int j = 1;j<k;j++) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }
        }
        return dummy.next;
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // head = [1,2,3,4,5] k = 2
    vector<int> nums{1,2,3,4,5};
    ListNode* head = create_list(nums);
    printList(head);
    head = s.reverseKGroup(head, 2);
    printList(head);
}