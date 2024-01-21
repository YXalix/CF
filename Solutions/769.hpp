#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> chunks;
        int now = -1;
        for (auto item : arr){
            if (item > now) {
                chunks.push(item);
                now = item;
            }
            else{
                while(!chunks.empty() && chunks.top() > item){
                    chunks.pop();
                }
                chunks.push(now);
            }
        }
        return chunks.size();
    }
};
// @lc code=end

inline void test(){
    Solution s;

}