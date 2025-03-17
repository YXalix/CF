#include "utils.hpp"
#include <deque>
#include <unordered_map>
#include <utility>
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* pre;
        Node* next;
        Node(int k=0, int v = 0): key(k), val(v) {};
    };

    void push_front(Node* node) {
        node->next = dummy->next;
        dummy->next->pre = node;
        dummy->next = node;
        node->pre = dummy;
    }

    void remove(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    /// 先检查是否存在这个key,如果不存在则返回nuptr
    /// 否则将这个node放到队首
    Node* get_node(int key) {
        if (!key_to_node.contains(key)) {
            return nullptr;
        }
        Node* node = key_to_node[key];
        remove(node);
        push_front(node);
        return node;
    }

    unordered_map<int, Node*> key_to_node;
    int caps;
    int cur;
    Node* dummy;

    LRUCache(int capacity) {
        dummy = new Node();
        dummy->next = dummy;
        dummy->pre = dummy;
        caps = capacity;
    }
    
    int get(int key) {
        auto node = get_node(key);
        if (node) return node->val;
        return -1;
    }
    
    void put(int key, int value) {
        auto node = get_node(key);
        if (node) {
            node->val = value;
            return;
        }

        node = new Node(key, value);
        key_to_node.insert({key, node});
        push_front(node);
        if (key_to_node.size() > caps) {
            Node* pre = dummy->pre;
            key_to_node.erase(pre->key);
            remove(pre);
            delete pre;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


inline void test(){
	LRUCache cache(5);
}