#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=2594 lang=cpp
 *
 * [2594] 修车的最少时间
 */

// @lc code=start
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = 1e18;
        //sort(ranks.begin(),ranks.end());
        long long ans = func(left, right, ranks,cars);
        return ans;
    }

    long long func(long long left, long long right, vector<int>& ranks, int &cars){
        if (right == left){
            return left;
        }
        long long mid = (right + left) / 2;
        int count = 0;
        for(auto i : ranks){
            int item = sqrt((mid / i));
            count += item;
            if (count >= cars){
                return func(left, mid, ranks,cars);
            }
        }
        return func(mid+1, right, ranks,cars);
    }

};
// @lc code=end

inline void test(){
    Solution s;
    vector<int> ranks = {4,2,3,1};
    int cars = 10;
    cout << s.repairCars(ranks, cars) << endl;

}