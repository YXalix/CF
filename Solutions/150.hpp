#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto& token : tokens)
        {
            if(token == "+" || token == "-" || token == "*" || token == "/")
            {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                if(token == "+") s.push(num1 + num2);
                else if(token == "-") s.push(num2 - num1);
                else if(token == "*") s.push(num1 * num2);
                else if(token == "/") s.push(num2 / num1);
            }
            else
            {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
// @lc code=end

inline void test(){
    Solution s;

}