#include<iostream>
#include<vector>
using namespace std;

void DFS(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& area) {
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0 || visited[i][j]) return;
    visited[i][j] = true;
    area++;
    DFS(i+1, j, m, n, grid, visited, area);
    DFS(i-1, j, m, n, grid, visited, area);
    DFS(i, j+1, m, n, grid, visited, area);
    DFS(i, j-1, m, n, grid, visited, area);
}

int main(){
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==1 && !visited[i][j]){
                int area = 0;
                DFS(i, j, m, n, grid, visited, area);
                ans = max(ans, area);
            }
        }
    }
    cout << ans << endl;
    return 0;
}