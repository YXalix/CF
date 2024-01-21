#include "utils.hpp"


class Solution {
public:
    int countTime(string time) {
        int ans = 1;
        if(time[0] == '?'){
            if (time[1] == '?') {
                ans = ans * 24;
            }
            else if(time[1] >= '4'){
                ans = ans*2;
            }else{
                ans = ans*3;
            }
        }else if(time[0] == '2'){
            if (time[1] == '?') {
                ans = ans * 4;
            }
        }else {
            if (time[1] == '?') {
                ans = ans * 10;
            }
        }
        if (time[3]=='?') {
            if(time[4] == '?'){
                ans = ans * 60;
            }else{
                ans = ans *6;
            }
        }else{
            if(time[4] == '?'){
                ans = ans * 10;
            }
        }
        return ans;
    }
};



inline void test(){
    string time = "??:00";
    Solution s;
    cout<<s.countTime(time)<<endl;
}
