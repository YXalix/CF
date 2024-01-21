#include "utils.hpp"
#include <string>
#include <vector>
/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */

// @lc code=start
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> m;
        for(string cpdomain : cpdomains){
            int pos = cpdomain.find(' ');
            int count = stoi(cpdomain.substr(0,pos));
            string domain = cpdomain.substr(pos+1);
            m[domain] += count;

            while(domain.find('.') != string::npos){
                domain = domain.substr(domain.find('.') + 1);
                m[domain] += count;
            }
        }
        // save answers
        for(auto& [domain, count]: m){
            ans.push_back(to_string(count) + " " + domain);
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;

}