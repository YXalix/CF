#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
    class Node {
        public:
        int val;
        Node* next;
        Node* prev;
        Node(int val) {
            this->val = val;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };
    Node* head;
    Node* tail;
    int size;
public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index >= size) {
            return -1;
        }
        auto cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        auto node = new Node(val);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        size++;
    }
    
    void addAtTail(int val) {
        auto node = new Node(val);
        if (tail == nullptr) {
            head = node;
            tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        } else if (index == size) {
            addAtTail(val);
        } else if (index == 0) {
            addAtHead(val);
        } else {
            auto node = new Node(val);
            auto cur = head;
            for (int i = 0; i < index; i++) {
                cur = cur->next;
            }
            node->next = cur;
            node->prev = cur->prev;
            cur->prev->next = node;
            cur->prev = node;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) {
            return;
        } else if (index == 0) {
            auto node = head;
            head = head->next;
            delete node;
        } else if (index == size - 1) {
            auto node = tail;
            tail = tail->prev;
            delete node;
        } else {
            auto cur = head;
            for (int i = 0; i < index; i++) {
                cur = cur->next;
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

inline void test(){
    MyLinkedList s;
    // ["MyLinkedList","addAtHead","addAtIndex","addAtTail","addAtHead","addAtIndex","addAtTail","addAtTail","addAtIndex","deleteAtIndex","deleteAtIndex","addAtTail"]
    // [[],[0],[1,4],[8],[5],[4,3],[0],[5],[6,3],[7],[5],[4]]
    s.addAtHead(0);
    s.addAtIndex(1, 4);
    s.addAtTail(8);
    s.addAtHead(5);
    s.addAtIndex(4, 3);
    s.addAtTail(0);
    s.addAtTail(5);
    s.addAtIndex(6, 3);
    s.deleteAtIndex(7);
    s.deleteAtIndex(5);
    s.addAtTail(4);
    cout << s.get(0) << endl;
}