#include "utils.hpp"
#include <unordered_map>
#include <utility>
/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
class LFUCache {
class node{
public:
    node* prev;
    node* next;
    int key;
    int value;
    int freq;
    node(int key= -1, int value = -1) {
        this->prev = nullptr;
        this->next = nullptr;
        this->key = key;
        this->value = value;
        this->freq = 1;
    }
};
private:
    int capacity;
    int minfreq;
    unordered_map<int, node*> key_to_node;
    unordered_map<int, node*> freq_to_node;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minfreq = 0;
    }

    node* createList(int freq) {
        node* dummy = new node();
        dummy->next = dummy;
        dummy->prev = dummy;
        return dummy;
    }

    void removeNode(node* n) {
        node* prev = n->prev;
        prev->next = n->next;
        n->next->prev = prev;
    }

    void push_front(int freq, node* n) {
        auto it = freq_to_node.find(freq);
        if (it == freq_to_node.end()) {
            it = freq_to_node.emplace(freq, createList(freq)).first;
        }
        node* dummy = it->second;
        n->next = dummy->next;
        dummy->next->prev = n;
        dummy->next = n;
        n->prev = dummy;
    }

    node* getNode(int key) {
        auto it = key_to_node.find(key);
        if (it == key_to_node.end()) {
            return nullptr;
        }
        node* n = it->second;
        removeNode(n);
        auto dummy = freq_to_node[n->freq];
        if (dummy->prev == dummy){
            freq_to_node.erase(n->freq);
            delete dummy;
            if (n->freq == minfreq) {
                minfreq++;
            }
        }
        n->freq++;
        push_front(n->freq, n);
        return n;
    }
    
    int get(int key) {
        node* n = getNode(key);
        if (n == nullptr) {
            return -1;
        }
        return n->value;
    }
    
    void put(int key, int value) {
        node* n = getNode(key);
        if (n != nullptr) {
            n->key = key;
            n->value = value;
            return;
        } else{
            if (key_to_node.size() == capacity) {
                node* dummy = freq_to_node[minfreq];
                node* last = dummy->prev;
                removeNode(last);
                key_to_node.erase(last->key);
                if (dummy->next == dummy && dummy->prev == dummy) {
                    freq_to_node.erase(minfreq);
                }
            }
            minfreq = 1;
            if (freq_to_node.find(minfreq) == freq_to_node.end()) {
                freq_to_node[minfreq] = createList(minfreq);
            }
            node* new_node = new node(key, value);
            push_front(minfreq, new_node);
            key_to_node[key] = new_node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

inline void test(){
    LFUCache* obj = new LFUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl;
    obj->put(3, 3);
    cout << obj->get(2) << endl;
    cout << obj->get(3) << endl;
    obj->put(4, 4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;


}