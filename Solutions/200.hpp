#include "utils.hpp"
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int k_zero_left(vector<int> &nums, int k){
        int n = nums.size();
        vector<long long int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++){
            
        }


    }
        

};
// @lc code=end

using namespace std;


/*
因数分解
对于一个数n，我们可以将其分解为n = p1^c1 * p2^c2 * ... * pk^ck
对于我们这题有用的因数为2和5，所以我们可以将n分解为n = 2^a * 5^b * x
那么如果需要至少k个0，那么我们剩下的数组里至少需要有k个2和5
问题就又变成了前缀和求解


*/


inline void test(){
    Solution sol;
// 5 2
// 2 5 3 4 20
    vector<int> nums{2, 5, 3, 4, 20};
    cout << sol.k_zero_left(nums, 5) << endl;
}