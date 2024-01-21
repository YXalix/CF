#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {

public:
    class node{
        public:
        int val;
        node* next;
        node(int val){
            next = nullptr;
            this->val = val;
        }
    };

    node* root;

    StockSpanner() {
        root = new node(0);
    }
    
    int next(int price) {
        node* p = new node(price);
        node* q = root;
        p->next = root->next;
        root->next = p;
        int ans = 0;
        while(q->next != nullptr && q->next->val <= price){
            q = q->next;
            ans++;
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

inline void test(){
   StockSpanner stockspanner = StockSpanner();
//     ["StockSpanner","next","next","next","next","next","next","next"]
// [[],[100],[80],[60],[70],[60],[75],[85]]
    cout << stockspanner.next(100) << endl;
    cout << stockspanner.next(80) << endl;
    cout << stockspanner.next(60) << endl;
    cout << stockspanner.next(70) << endl;
    cout << stockspanner.next(60) << endl;
    cout << stockspanner.next(75) << endl;
    cout << stockspanner.next(85) << endl;

}