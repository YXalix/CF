#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(0, head);
        auto first = dummy;
        auto second = dummy;
        for (int i = 0; i < n + 1; i++) {
            first = first->next;
        }
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};
// @lc code=end

inline void test(){
    Solution s;
// 输入：head = [1,2,3,4,5], n = 2
// 输出：[1,2,3,5]
    auto nums = vector<int>{1,2,3,4,5};
    auto head = create_list(nums);
    auto res = s.removeNthFromEnd(head, 2);
    while (res != nullptr) {
        cout << res->val << endl;
        res = res->next;
    }
}