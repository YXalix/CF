#include "utils.hpp"
#include <vector>
/*
 * @lc app=leetcode.cn id=1993 lang=cpp
 *
 * [1993] 树上的操作
 */

// @lc code=start
class LockingTree {
private:
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> lockednode;
public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        this->parent = parent;
        this->lockednode = vector<int>(n,-1);
        this->children = vector<vector<int>>(n,vector<int>());
        for (int i = 0; i<n;i++){
            int var = i;
            while (parent[var] != -1){
                this->children[parent[var]].push_back(i);
                var = parent[var];
            }
        }
    }
    
    bool lock(int num, int user) {
        if (this->lockednode[num] == -1){
            this->lockednode[num] = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if (this->lockednode[num] == user){
            this->lockednode[num] = -1;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        if (this->lockednode[num] == -1){
            bool flag = true;
            int x = num;
            while (x != -1){
                if (this->lockednode[x] != -1){
                    flag = false;
                    break;
                }
                x = this->parent[x];
            }
            if (flag){
                flag = false;
                for (auto item : this->children[num]){
                    if (this->lockednode[item] != -1){
                        flag = true;
                    }
                }
                if (flag == true){
                    this->lockednode[num] = user; 
                    for (auto item : this->children[num]){
                        if (this->lockednode[item] != -1){
                            this->lockednode[item] = -1;
                        }
                    }
                    return true;
                }
            }

        }
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
// @lc code=end

inline void test(){
    vector<int> parent{-1,0,0,1,1,2,2};
    LockingTree* obj = new LockingTree(parent);
    obj->lock(4, 5);
    obj->upgrade(0, 1);
    obj->lock(0, 1);
}