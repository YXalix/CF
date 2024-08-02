#include "utils.hpp"
#include <functional>
#include <stack>
#include <vector>
/*
 * @lc app=leetcode.cn id=1872 lang=cpp
 *
 * [1872] 石子游戏 VIII
 */

// @lc code=start
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int sum = 0;
        int n = stones.size();
        for (auto i : stones) {
            sum += i;
        }
        int f = sum;
        for (int i = n-1;i>=0;i--) {
            sum -= stones[i];
            f = max(f, sum - f);
        }
        return f;
    }
    static bool cmp(int a, int b) {
        return a >= b;
    }

    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(),cards.end(),greater<int>());
        printIntVector(cards);
        int odd, even = -1;
        int s = 0;
        for (int i = 0;i<cnt;i++) {
            s += cards[i];
            if (cards[i] & 1) {
                odd = cards[i];
            } else {
                even = cards[i];
            }
        }
        if (s % 2 == 0) {
            return s;
        }
        int ans= 0;
        for (int i = cnt; i < cards.size(); ++i) {
            // 如果找到一个偶数并且之前有奇数，尝试替换。
            if (cards[i] % 2 == 0 && odd!= -1) {
                ans = max(ans, s - odd + cards[i]);
            } 
            // 如果找到一个奇数并且之前有偶数，尝试替换。
            else if (cards[i] % 2!= 0 && even!= -1) {
                ans = max(ans, s - even + cards[i]); // 替换 even 为当前奇数。
            }
        }
        // 返回最大可能的得分。
        return ans;
    }
};
// @lc code=end


inline void test(){
	Solution s;
    vector<int> nums = {3,20,9,4,17,19,8,5,18,2,13,18,2,17,7,20,5,4,3,15,13,7,18,6,11,20,15,4,1,9,6,8,2,8,7,5,10,17,14,3,10,20,7,9,5,2,3,2,14,11,3,13,20,11,6,1,6,8,2,18,7,3,6,6,19,12,20,2,2,11,19,9,9,18,16,17,13,1,18,7,3,16,1,14,8,20,11,15,15,19,19,20};
    cout<<s.maxmiumScore(nums,4)<<endl;
}