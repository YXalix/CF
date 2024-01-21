#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=1366 lang=cpp
 *
 * [1366] 通过投票对团队排名
 */

// @lc code=start
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> vote(26, vector<int>(27, 0));
        for (auto v: votes) {
            for (int i = 0; i < v.length(); i++) { // 字母下标 i 即为名次
                int seq = v[i] - 'A'; // seq为字母的序号，即所在行，A->0, B->1, ..., Z->25
                vote[seq][i]++;
                vote[seq].back() = 26 - seq; // 记录优先级，A->26, B->25, ..., Z->1
            }
        }
        sort(vote.begin(), vote.end(), greater<vector<int>>());
        string res;
        for (int i = 0; i < vote.size(); i++) {
            if (!vote[i].back()) {
                break;
            }
            res.push_back(26 - vote[i].back() + 'A');
        }
        return res;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    vector<string> v1 = {"WXYZ","XYZW"};
    cout<<s.rankTeams(v1)<<endl;
}