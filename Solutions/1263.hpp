#include "utils.hpp"

class Solution {
public:
    struct node{
        int x;
        int y;
    };
    int m,n;
    queue<node> person;
    queue<node> box;
    node target;
    int ans = 0;
    int dp[500][500];
    int gridv[21][21] = {0};
    void getinitpos(vector<vector<char>>& grid){
        for(int i = 0;i<m;i++){
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'T') {
                    target = {i,j};
                }else if (grid[i][j] == 'B') {
                    box.push({i,j});
                    grid[i][j] = '.';
                }else if (grid[i][j] == 'S') {
                    person.push({i,j});
                    grid[i][j] = '.';
                }
            }
        }
    }

    void updatePersionFiled(vector<vector<char>>& grid){
        node personnow = person.front();
        queue<node> q;
        q.push({personnow.x,personnow.y});
        int bx,by;
        while (!q.empty()) {
            personnow = q.front();
            gridv[personnow.x][personnow.y] = 1;
            if(checkvaildPerson(grid, personnow.x+1, personnow.y)&&gridv[personnow.x+1][personnow.y] == 0){
                    q.push({personnow.x+1,personnow.y});
            }
            if(checkvaildPerson(grid, personnow.x-1, personnow.y)&&gridv[personnow.x-1][personnow.y] == 0){
                    q.push({personnow.x-1, personnow.y});
            }
            if(checkvaildPerson(grid, personnow.x, personnow.y+1) && gridv[personnow.x][personnow.y+1] == 0){
                    q.push({personnow.x, personnow.y+1});
                }
            if(checkvaildPerson(grid, personnow.x, personnow.y-1) && gridv[personnow.x][personnow.y-1] == 0) {
                    q.push({personnow.x, personnow.y-1});
            }
            q.pop();
        }

    }

    bool checkvaildBox(vector<vector<char>>& grid,int x,int y){
        if (x >= 0 && x < m && y >= 0 && y<n ) {
            if(grid[x][y] == 'T' || grid[x][y] == '.' || grid[x][y] == 'B'){
                return true;
            }
        }
        return false;
    }
    bool checkvaildPerson(vector<vector<char>>& grid,int x,int y){
        if (x >= 0 && x < m && y >= 0 && y<n ) {
            if(grid[x][y] == 'T' || grid[x][y] == '.' || grid[x][y] == 'S'){
                return true;
            }
        }
        return false;
    }

    void appandBoxNextStep(vector<vector<char>>& grid){
        node boxnow = box.front();
        node personnow = person.front();
        int bx = boxnow.x;
        int by = boxnow.y;
        int px = personnow.x;
        int py = personnow.y;
        int s1,s2;
        int b1,b2;
        //grid[personnow.x][personnow.y] = 'S';
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                cout<<grid[i][j];
            }
            cout<<"|";
            for(int j = 0;j<n;j++){
                cout<<gridv[i][j];
            }
            cout<<"|";
            cout<<endl;
        }
        cout<<"**************************"<<endl;
        b1 = bx*n+by;
        s1 = px*n+py;
        if(checkvaildBox(grid, bx+1, by)){
            if (checkvaildPerson(grid, bx-1, by) && gridv[bx-1][by] == 1) {
                b2 = (bx+1)*n+by;
                s2 = bx*n + by;
                if(dp[b2][s2] > dp[b1][s1]+1 ){
                    box.push({bx+1,by});
                    person.push({bx,by});
                    dp[b2][s2] = dp[b1][s1]+1;
                }
            }
        }
        if(checkvaildBox(grid, bx-1, by))
            if (checkvaildPerson(grid, bx+1, by) && gridv[bx+1][by] == 1) {
                b2 = (bx-1)*n+by;
                s2 = bx*n + by;
                if(dp[b2][s2] > dp[b1][s1]+1 ){
                    box.push({bx-1,by});
                    person.push({bx,by});
                    dp[b2][s2] = dp[b1][s1]+1;
                }
            }
        if(checkvaildBox(grid, bx, by+1))
            if (checkvaildPerson(grid, bx, by-1) && gridv[bx][by-1] == 1) {
                b2 = (bx)*n+by+1;
                s2 = bx*n + by;
                if(dp[b2][s2] > dp[b1][s1]+1 ){
                    box.push({bx,by+1});
                    person.push({bx,by});
                    dp[b2][s2] = dp[b1][s1]+1;
                }
            }
        if(checkvaildBox(grid, bx, by-1))
            if (checkvaildPerson(grid, bx, by+1) && gridv[bx][by+1] == 1) {
                b2 = (bx)*n+by-1;
                s2 = bx*n + by;
                if(dp[b2][s2] > dp[b1][s1]+1 ){
                    box.push({bx,by-1});
                    person.push({bx,by});
                    dp[b2][s2] = dp[b1][s1]+1;
                }
            }
        person.pop();
        //grid[personnow.x][personnow.y] = '.';
    }

    int minPushBox(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i<500; i++) {
            for(int j = 0;j<500;j++){
                dp[i][j] = INT_MAX;
            }
        }
        getinitpos(grid);
        box.push({m,n});
        node boxnow = box.front();
        node personnow = person.front();
        dp[boxnow.x*n+boxnow.y][personnow.x*n+personnow.y] = 0;
        while(!box.empty()) {
            for (int i = 0; i<m; i++) {
                for(int j = 0;j<n;j++){
                        gridv[i][j] = 0;
                }
            }
            boxnow = box.front();

            if(box.front().x == m && box.front().y == n){
                box.pop();
                if (box.empty()) {
                    return -1;
                }
                box.push({m,n});
                ans++;
                continue;
            }
            if(boxnow.x == target.x && boxnow.y == target.y){
                return ans;
            }
            grid[boxnow.x][boxnow.y] = 'B';
            //updateState(grid, boxnow);
            updatePersionFiled(grid);

            appandBoxNextStep(grid);
            box.pop();
            grid[boxnow.x][boxnow.y] = '.';
        }
        return -1;
    }
};


inline void test(int, char**) {
    vector<vector<char>> grid = {{'#','.','.','#','T','#','#','#','#'},
    {'#','.','.','#','.','#','.','.','#'},
    {'#','.','.','#','.','#','B','.','#'},
    {'#','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','#','.','S','#'},
    {'#','.','.','#','.','#','#','#','#'}};

    vector<vector<char>> grid1 = {{'#','#','#','#','#','#'},
    {'#','T','#','#','#','#'},{'#','.','.','B','.','#'},
    {'#','.','#','#','.','#'},
    {'#','.','.','.','S','#'},
    {'#','#','#','#','#','#'}};

    vector<vector<char>> grid2 = {{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','#','#','#','#'},
    {'#','.','.','.','#','#','.','#','#','#','#','.','#','#','#','.','#','#','T','#'},
    {'#','.','.','.','.','.','.','#','.','#','.','.','#','#','#','.','#','#','.','#'},
    {'#','.','.','.','#','.','.','.','.','.','.','.','#','#','#','.','#','#','.','#'},
    {'#','.','#','.','.','.','.','.','.','.','.','.','#','#','#','.','#','#','.','#'},
    {'#','.','#','.','#','#','#','#','#','#','#','.','#','#','#','.','#','#','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
    {'#','.','B','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
    {'#','.','.','.','.','.','.','.','S','.','.','.','.','.','.','.','#','.','.','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};

    Solution s;
    int ans = s.minPushBox(grid2);
    cout<<ans;
}