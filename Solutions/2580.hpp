#include "utils.hpp"
#include <algorithm>
#include <vector>
/*
 * @lc app=leetcode.cn id=2580 lang=cpp
 *
 * [2580] 统计将重叠区间合并成组的方案数
 */

// @lc code=start
class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] < b[0]) {
            return true;
        } else if (a[0] == b[0]) {
            return a[1] < b[0];
        } else {
            return false;
        }
    }

    int c_sum(int num) {
        int ans = 1;
        for (int i = 0;i<num;i++){
            ans = ans * 2;
            ans = ans % (1000000007);
        }
        return ans;
    }

    


    int countWays(vector<vector<int>>& ranges) {
        int len = ranges.size();
        sort(ranges.begin(), ranges.end(), cmp);
        int count = 0;
        int cur = 0;
        for (int i = 0;i < len - 1; i++) {
            if (ranges[cur][1] >= ranges[i+1][0]) {
                ranges[cur][1] = max(ranges[cur][1], ranges[i+1][1]);
            } else {
                cur++;
                ranges[cur][0] = ranges[i+1][0];
                ranges[cur][1] = ranges[i+1][1];
            }
        }
        return c_sum(cur + 1);
    }
};
// @lc code=end

inline void test(){
    Solution s;
    // [[34,56],[28,29],[12,16],[11,48],[28,54],[22,55],[28,41],[41,44]]
    vector<vector<int>> ranges = {{34,56},{28,29},{12,16},{11,48},{28,54},{22,55},{28,41},{41,44}};
    cout << s.countWays(ranges) << endl;
}