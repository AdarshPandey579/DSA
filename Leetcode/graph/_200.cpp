#include<iostream>
#include<vector>
using namespace std;

void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid, int m, int n){
    if(i<0 || i>=m || j<0 || j>=n || visited[i][j] || grid[i][j]=='0') return;

    visited[i][j] = true;
    dfs(i+1, j, visited, grid, m, n);
    dfs(i-1, j, visited, grid, m, n);
    dfs(i, j+1, visited, grid, m, n);
    dfs(i, j-1, visited, grid, m, n);
}

int main(){
    vector<vector<char>> grid = {{'1','1','0','0','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','1','0','0'},
                                 {'0','0','0','1','1'}};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int islands = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && grid[i][j]=='1'){
                dfs(i, j, visited, grid, m, n);
                islands++;
            }
        }
    }

    cout << islands;
    return 0;
}