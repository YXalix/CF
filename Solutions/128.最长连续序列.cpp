#include "utils.hpp"
#include <unordered_map>
#include <unordered_set>
/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    unordered_set<int> nums_new;
    unordered_map<int, int> fa;
    unordered_map<int, int> sz;
    int find(int num) {
        if (fa[num] != num) {
            fa[num] = find(fa[num]);
        }
        return fa[num];
    }

    void merge(int num1, int num2) {
        num1 = find(num1);
        num2 = find(num2);
        if (num1 != num2) {
            fa[num1] = num2;
            sz[num2] += sz[num1];
        }
    }

    int longestConsecutive(vector<int>& nums) {
        printVector(nums);
        for (auto num : nums) {
            nums_new.insert(num);
        }
        for (auto num : nums_new) {
            fa[num] = num;
            sz[num] = 1;
        }
        printHashSet(nums_new);

        for (auto item : nums_new) {
            if (fa.find(item + 1) != fa.end()) {
                merge(item, item+1);
                printHashMap(fa);
                printHashMap(sz);
                cout<<"__________"<<endl;
            }
        }
        int ans = 0;
        printHashMap(fa);
        printHashMap(sz);
        for (auto item : sz) {
            ans = max(ans, item.second);
        }
        return ans;
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // 100,4,200,1,3,2
    // vector<int> nums = 
    // {
    //     100,4,200,1,3,2
    // };
    // 0,3,7,2,5,8,4,6,0,1
    vector<int> nums = 
    {
        0,3,7,2,5,8,4,6,0,1
    };
    cout << s.longestConsecutive(nums) << endl;
}