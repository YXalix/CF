#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=1871 lang=cpp
 *
 * [1871] 跳跃游戏 VII
 */

// @lc code=start
class Solution {
public:
    struct block{
        int l;
        int r;
        block(int l, int r):l(l),r(r){}
    };

    int n;
    bool canReach(string s, int minJump, int maxJump) {
        n = s.size();
        block b(0,1);
        stack<block> st;
        st.push(b);
        while (!st.empty()){
            block b = st.top();
            st.pop();
            for (int i = b.l;i<b.r;i++){
                if (i >= n){
                    return false;
                }
                if (i == n-1){
                    if (s[i] == '1'){
                        return false;
                    }
                    return true;
                }
                if (s[i] == '1') continue;
                int newl = max(i+minJump,b.r);
                block nb(newl,i+maxJump+1);
                if (st.empty()){
                    st.push(nb);
                }
                else if (nb.l <= st.top().r){
                    st.top().r = nb.r;
                }else{
                    st.push(nb);
                }
            }
        }
        return false;
    }

};
// @lc code=end

inline void test(){
    Solution s;
    // "011000001011110000"
    // 4
    // 7
    

}