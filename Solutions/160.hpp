#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// a + c + b = b + c + a
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto curA = headA;
        auto curB = headB;
        while (curA != curB) {
            if (curA != nullptr) {
                curA = curA->next;
            } else {
                curA = headB;
            }
            if (curB != nullptr) {
                curB = curB->next;
            } else {
                curB = headA;
            }
        }
        return curA;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}