#include "utils.hpp"
/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

// @lc code=start
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        priority_queue<int> big_heap;
        int sum = 0;
        for (auto item : courses){
            if (item[0] + sum <= item[1]){
                sum += item[0];
                big_heap.push(item[0]);
            }
            else{
                if (big_heap.empty() || big_heap.top() <= item[0]){
                    continue;
                }
                else{
                    sum -= big_heap.top();
                    sum += item[0];
                    big_heap.pop();
                    big_heap.push(item[0]);
                }
            }
        }
        return big_heap.size();
    }
};
// @lc code=end

inline void test(){
    Solution s;
    // [[3,2],[4,3]]
    vector<vector<int>> courses = {{3,2},{4,3}};
    cout << s.scheduleCourse(courses) << endl;
}