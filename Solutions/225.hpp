#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
    queue<int> q;

public:
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int len = q.size();
        for (int i = 0; i < len - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        int len = q.size();
        for (int i = 0; i < len - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q.push(ans);
        q.pop();
        return ans;
    }
    
    bool empty() {
        if (q.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

inline void test(){
    // ["MyStack","push","push","top","pop","empty"]
    // [[],[1],[2],[],[],[]]
    MyStack s;
    s.push(1);
    s.push(2);
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.empty() << endl;
}