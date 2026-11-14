#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}, {-1,1}, {1,1}, {-1,-1}, {1,-1}};

bool isSafe(int x, int y, int m, int n){
    return x>=0 && x<m && y>=0 && y<n;
}

int main(){
    vector<vector<int>> grid = {{0,0,0},
                                {1,1,0},
                                {1,1,0}};
    int m = grid.size();
    int n = grid[0].size();
    if(grid[0][0] == 1 || grid[m-1][n-1] == 1) {
        cout << -1 << endl;
        return 0;
    }
        
    int level = 0;
    queue<pair<int,int>> q;
    q.push({0, 0});
    grid[0][0] = 1;
    while(!q.empty()){
        int s = q.size();
        level++;
        while(s--){
            pair<int, int> p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();
            if(x == m-1 && y == n-1) {
                cout << level << endl;
                return 0;
            }
            for(auto dir : directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                if(isSafe(x_, y_, m, n) && grid[x_][y_]==0 ){
                    q.push({x_,y_});
                    grid[x_][y_] = 1;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}