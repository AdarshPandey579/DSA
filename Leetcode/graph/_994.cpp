#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void rotten(int r,int c,int m,int n,vector<vector<int>>& grid,vector<vector<bool>>& visited,int& fresh, queue<pair<int,int>>& q){
    if(r<0 || r>=m || c<0 || c>=n || visited[r][c] || grid[r][c]!=1) return;
    q.push({r,c});
    visited[r][c] = true;
    fresh--;
}

int main(){
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    int m = grid.size();
    int n = grid[0].size();
    int fresh = 0;
    int time = 0;
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    queue<pair<int,int>> q;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==2) {
                q.push({i,j});
                visited[i][j] = true;
            }else if(grid[i][j]==1) fresh++;
        }
    }
    while(!q.empty() && fresh>0){
        time++;
        int s = q.size();
        while(s--){
            pair<int,int> f = q.front();
            q.pop();
            int r = f.first;
            int c = f.second;
            rotten(r+1, c, m, n, grid, visited, fresh, q);
            rotten(r-1, c, m, n, grid, visited, fresh, q);
            rotten(r, c+1, m, n, grid, visited, fresh, q);
            rotten(r, c-1, m, n, grid, visited, fresh, q);
        }
    }
    cout << (fresh==0 ? time : -1) << endl;
    return 0;
}