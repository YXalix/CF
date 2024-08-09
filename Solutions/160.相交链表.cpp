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
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode* pA = headA, *pB = headB;
        while (pA != pB) {
            // headA len = m, headB len = n
            // 如果没有交点, pA和pB会同时到达nullptr 从而退出循环,也就是答案
            pA = pA == nullptr? headB: pA->next;
            pB = pB == nullptr? headA: pB->next;
        }
        return pA;
    }
};
// @lc code=end


inline void test(){
	Solution s;
}