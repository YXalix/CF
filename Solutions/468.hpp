#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 */

// @lc code=start
class Solution {
public:

    /*
        1. 以.分割字符串
        2. 检查每个字符串是否是合法的数字
        3. 检查每个数字是否在0-255之间
    */
    bool validIPv4(string& queryIP){
        vector<string> parts;
        split(queryIP, parts, '.');
        if(parts.size() != 4) return false;
        for(auto &part: parts){
            if(part.size() == 0 || part.size() > 3) return false;
            if(part.size() > 1 && part[0] == '0') return false;
            for(auto &c: part){
                if(!isdigit(c)) return false;
            }
            int num = stoi(part);
            if(num < 0 || num > 255) return false;
        }
        return true;
    }

    /*
        1. 以:分割字符串
        2. 检查每个字符串是否是合法的数字
        3. 检查每个数字是否在0-65535之间
    */
    bool validIPv6(string& queryIP){
        vector<string> parts;
        split(queryIP, parts, ':');
        if(parts.size() != 8) return false;
        for(auto &part: parts){
            if(part.size() == 0 || part.size() > 4) return false;
            for(auto &c: part){
                if (!isdigit(c)) {
                    if (c >= 'a' && c <= 'f') continue;
                    if (c >= 'A' && c <= 'F') continue;
                    return false;
                }
            }
        }
        return true;
    }

    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos) {
            return validIPv4(queryIP) ? "IPv4" : "Neither";
        }
        return validIPv6(queryIP) ? "IPv6" : "Neither";
    }

    void split(string &s,vector<string>&ip,char c){
        int start = 0;
        for(int r = 0; r < s.size(); r++){
            if(s[r] == c){
                ip.push_back(s.substr(start, r - start));
                start = r + 1;
            }
        }
        ip.push_back(s.substr(start, s.size() - start));
    }

};
// @lc code=end

inline void test(){
    Solution s;

}