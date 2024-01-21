#include "utils.hpp"
#include <queue>
#include <sys/_types/_key_t.h>
#include <unordered_map>
#include <vector>
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {

    class node{
        public:
        node* next = nullptr;
        node* pre = nullptr;
        int val;
        int key;

        node(int value,int key=-1){
            this->val = value;
            this->next = nullptr;
            this->next = nullptr;
            this->key = key;
        }
    };

private:
    node* root = nullptr;
    node* tail = nullptr;
    int capacity;
    int length;
    unordered_map<int, node*> mp;
public:

    LRUCache(int capacity) {
        this->capacity = capacity;
        root = new node(0);
        tail = new node(0);
        root->next = tail;
        tail->pre = root;
        length = 0;
    }
    
    int get(int key) {
        if (mp.count(key) == 0){
            return -1;
        }
        node* p = mp[key];
        updatelocation(p);
        return p->val;
    }

    void updatelocation(node* p){
        // remove
        p->pre->next = p->next;
        p->next->pre = p->pre;

        //insert
        p->pre = tail->pre;
        p->next = tail;
        p->pre->next = p;
        tail->pre = p;
    }
    
    void put(int key, int value) {
        if (mp.count(key) == 1){
            node* p = mp[key];
            p->val = value;
            updatelocation(p);
        }else{
            node* p = new node(value,key);
            //insert
            p->pre = tail->pre;
            p->next = tail;
            p->pre->next = p;
            tail->pre = p;
            mp[key] = p;
            if (length == capacity){
                node* t = root->next;
                root->next = t->next;
                t->next->pre = root;
                mp.erase(t->key);
                delete t;
            }else{
                length++;
            }
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
    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout << obj->get(1) << endl;
    obj->put(3,3);
    cout << obj->get(2) << endl;
    obj->put(4,4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;
}