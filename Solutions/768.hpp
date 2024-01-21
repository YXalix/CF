#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=768 lang=cpp
 *
 * [768] 最多能完成排序的块 II
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> chunks;
        int ans = 0;
        int n = arr.size();
        int maxnum = -1;
        chunks.push(-1);
        for (int i = 0; i < n;i++){
            if (arr[i] > chunks.top()){
                chunks.push(arr[i]);
                maxnum = arr[i];
            }
            else {
                while(chunks.top() > arr[i]){
                    chunks.pop();
                }
                chunks.push(maxnum);
            }
        }
        return chunks.size()-1;
    }

    int logicalNeg(int x) {
        int var1 = 1 << 31;
        int var2 = var1 + x;
        int var3 = ~var2 + 1;
        int var4 = ~((var2 >> 31) & (var3>>31)) + 1;
        return var4 & 1;
    }

int logicalNeg1(int x) {
  // int var1 = 1 << 31;
  // int var2 = var1 + x;
  // int var3 = ~var2 + 1;
  // int var4 = ~((var2 >> 31) & (var3>>31)) + 1;
  int var1 = (x >> 31) & 1;
  int var2 = ((~(x) + 1) >> 31) & 1;
  return ((var1 ^ 1) & (var2 ^ 1));
}
}; 
// @lc code=end

inline void test(){
    Solution s;
    vector<int> arr = {0,3,0,3,2};
    //cout << s.maxChunksToSorted(arr) << endl;
    cout<<s.logicalNeg1(-2147483648);

}