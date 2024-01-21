#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=2511 lang=cpp
 *
 * [2511] 最多可以摧毁的敌人城堡数目
 */

// @lc code=start
class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = 0;
        int i = 0;
        int count = 0;
        while ( i < forts.size()){
            if (forts[i] == 1){
                count = 0;
                i++;
                while(i < forts.size() && forts[i] == 0){
                    i++;
                    count++;
                }
                if (i == forts.size()){
                    break;
                }
                if (forts[i]==-1){
                    ans = max(ans,count);
                }
            }
            else if (forts[i] == -1){
                count = 0;
                i++;
                while(i < forts.size() && forts[i] == 0){
                    i++;
                    count++;
                }
                if (i == forts.size()){
                    break;
                }
                if (forts[i]==1){
                    ans = max(ans,count);
                }
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
// @lc code=end

inline void test(){
    Solution s;
    vector<int> v1 = {1,0,1,0,1,1,1,0,1,1,0,1,1,0,1,1,0};
    cout<<s.captureForts(v1)<<endl;

}