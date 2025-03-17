#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        ListNode dummy{};
        ListNode* cur = &dummy;
        while (h1 && h2) {
            if (h1->val < h2->val) {
                cur->next = h1;
                h1 = h1->next;
            } else {
                cur->next = h2;
                h2 = h2->next;
            }
            cur = cur->next;
        }
        cur->next = h1? h1:h2;
        return dummy.next;
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int r){
        if(l == r) return lists[l];
        int mid = (r + l) / 2;
        ListNode* l1 = merge(lists, l, mid);
        ListNode* l2 = merge(lists, mid + 1, r);
        return mergeTwoLists(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // [[1,4,5],[1,3,4],[2,6]]
    vector<ListNode*> lists{
        create_list({1,4,5}),
        create_list({1,3,4}),
        create_list({2,6})
    };
    printList(s.mergeKLists(lists));
}