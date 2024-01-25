#include "utils.hpp"
#include <stack>
/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {

    }
    
    void push(int x) {
        s2.push(x);
    }
    
    int pop() {
        if (s1.empty()) {
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        if (s1.empty()) {
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        return s1.top();
    }
    
    bool empty() {
        if (s1.empty() && s2.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

inline void test(){
    MyQueue* obj = new MyQueue();
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
}