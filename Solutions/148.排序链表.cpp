#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        int n = 0;
        ListNode dummy{};
        dummy.next = head;
        ListNode* cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }
        int intv = 1;
        while (intv < n) {
            cur = &dummy;
            head = dummy.next;
            while (head) {
                ListNode* h1 = head;
                int i = intv;
                while (i && head) {
                    i--;
                    head = head->next;
                }
                // 如果i没有减到0, 说明此时不存在h2
                if (i) break;
                ListNode* h2 = head;
                i = intv;
                while (i && head) {
                    i--;
                    head = head->next;
                }
                // c1, c2 分别代表h1 和 h2 的长度
                int c1 = intv, c2 = intv - i;
                while (c1 && c2) {
                    if (h1->val < h2->val) {
                        cur->next = h1;
                        h1 = h1->next;
                        c1--;
                    } else {
                        cur->next = h2;
                        h2 = h2->next;
                        c2--;
                    }
                    cur = cur->next;
                }
                cur->next = c1? h1:h2;
                while (c1 > 0 || c2 > 0) {
                    cur = cur->next;
                    c1--;c2--;
                }
                cur->next = head;
            }
            intv += intv;
        }
        return dummy.next;
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // [4,2,1,3]
    vector<int> nums = {4,2,1,3};
    ListNode* head = create_list(nums);
    printList(s.sortList(head));
}