#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=2007 lang=cpp
 *
 * [2007] 从双倍数组中还原原数组
 */

// @lc code=start
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2 != 0) return {};
        unordered_map<int, int> cnt;
        for(auto &i : changed) cnt[i]++;
        if (cnt[0] % 2 != 0) return {};
        int cnt0 = cnt[0];
        cnt.erase(0);
        vector<int> ans(cnt0 / 2, 0);

        for (auto &i : cnt){
            int x = i.first;
            // 如果 x/2 在 cnt 中, 就跳过
            if (x % 2 == 0 && cnt.count(x / 2)) continue;
            if (cnt[x] > cnt[2 * x]) return {};
            while (cnt.contains(x)) {
                int c = cnt[x];
                if (c > cnt[2 * x]) return {};
                ans.insert(ans.end(), c, x);
                if (c == cnt[2 * x]) x = 4 * x; // 2 * x 用完了
                else {
                    cnt[2 * x] -= c;
                    x = 2 * x;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    
}