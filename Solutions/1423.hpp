#include "utils.hpp"



class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> left;
        vector<int> right;
        left.resize(k+1);
        right.resize(k+1);

        int len = cardPoints.size();
        for(int i = 0;i<k;i++){
            left[i+1] = left[i] + cardPoints[i];
            right[i+1] = right[i] + cardPoints[len-i-1];
        }
        int ans = 0;
        for(int i = 0;i<=k;i++){
            if(ans < left[i] + right[k-i]){
                ans = left[i] + right[k-i];
            }
        }
        return ans;
    }
};