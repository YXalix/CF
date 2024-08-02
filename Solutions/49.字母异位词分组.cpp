#include "utils.hpp"
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (string& s : strs) {
            auto tmp = s;
            sort(tmp.begin(),tmp.end());
            m[tmp].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (auto item : m) {
            ans.emplace_back(std::move(item.second));
        }
        return ans;
    }
};
// @lc code=end


inline void test(){
	Solution s;
    // ["eat", "tea", "tan", "ate", "nat", "bat"]
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = s.groupAnagrams(strs);
}