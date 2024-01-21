#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        for(int i = 1; i + 1 < flowerbed.size();i++){
            if (flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                n--;
            }
        }
        if (n <= 0){
            return true;
        }
        return false;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}