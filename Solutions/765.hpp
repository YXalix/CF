#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */

// @lc code=start
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        record.resize(row.size());
        for (int i = 0; i < row.size(); i++) {
            record[row[i]] = i;
        }

        int count = 0;
        for (int i = 0; i < row.size() - 1; i += 2) {
            int wife =  row[i]^1;
            if (wife != row[i + 1]) {
                int newPos = record[wife];
                record[row[i + 1]] = newPos;
                swap(row[newPos], row[i + 1]);
                count++;
            }
        }
        return count;
    }
private:
    vector<int> record;
};
// @lc code=end

inline void test(){
    Solution s;
    // [5,4,2,6,3,1,0,7]

    vector<int> row = {5,4,2,6,3,1,0,7};
    cout << s.minSwapsCouples(row) << endl;

}