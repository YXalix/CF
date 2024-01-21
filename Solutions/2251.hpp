#include "utils.hpp"
#include <algorithm>
#include <vector>
/*
 * @lc app=leetcode.cn id=2251 lang=cpp
 *
 * [2251] 花期内花的数目
 */

// @lc code=start
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        vector<int> start(n,0),end(n,0);
        for (int i = 0;i< n;i++){
            start[i] = flowers[i][0];
            end[i] = flowers[i][1];
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        vector<int> res(people.size(),0);
        for (int i = 0;i< people.size();i++){
            int it = lower_bound(end.begin(),end.end(),people[i]) - end.begin();
            int it2 = upper_bound(start.begin(),start.end(),people[i]) - start.begin();
            res[i] = it2 - it;
        }
        return res;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}