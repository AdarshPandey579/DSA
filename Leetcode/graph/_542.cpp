#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
bool valid(int x, int y, int m, int n){
    return x>=0 && x<m && y>=0 && y<n;
}

int main(){
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    int m = mat.size();
    int n = mat[0].size();
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    int level = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 0){
                q.push({i,j});
                visited[i][j]=true;
            }
        }
    }
    while(!q.empty()){
        level++;
        int s = q.size();
        while(s--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto dir : directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                if(valid(x_, y_, m, n) && !visited[x_][y_]){
                    mat[x_][y_] = level;
                    q.push({x_,y_});
                    visited[x_][y_] = true;
                }
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}