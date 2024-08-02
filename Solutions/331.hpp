#include "utils.hpp"
#include <stack>
/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder.append(",");
        int len = preorder.size();
        stack<int> s;
        s.push(1);
        for (int i = 1;i<len;i++){
            if (preorder[i] == ',') {
                // nullptr
                if (preorder[i-1] == '#') {
                    s.top()++;
                    while (s.top() == 2) {
                        s.pop();
                        if (s.empty() && i == len - 1) {
                            return true;
                        } else if (s.empty()) {
                            return false;
                        }
                        s.top()++;
                    }
                } else {
                    s.push(0);
                }
            }
        }
        if (s.empty()) {
            return true;
        }
        return false;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    s.isValidSerialization(preorder);
}