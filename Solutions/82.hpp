#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = nullptr;
        ListNode* p = nullptr;
        ListNode* q = head;
        while(q != nullptr){
            if(q->next == nullptr || q->val != q->next->val){
                if(ans == nullptr){
                    ans = q;
                    p = q;
                }else{
                    p->next = q;
                    p = p->next;
                }
            }else{
                while(q->next != nullptr && q->val == q->next->val){
                    q = q->next;
                }
            }
            q = q->next;
        }
        if(p != nullptr){
            p->next = nullptr;
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    p = p->next;
    p->next = nullptr;
    p = s.deleteDuplicates(head);
}