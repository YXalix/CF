#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *p = head;
        while(p){
            Node *tmp = new Node(p->val);
            tmp->next = p->next;
            p->next = tmp;
            p = tmp->next;
        }
        p = head;
        while(p){
            if(p->random){
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        p = head;
        while(p){
            Node *tmp = p->next;
            p->next = tmp->next;
            if(tmp->next){
                tmp->next = tmp->next->next;
            }
            p = p->next;
        }
        return head->next;
    }
};
// @lc code=end


inline void test(){
	Solution s;
}