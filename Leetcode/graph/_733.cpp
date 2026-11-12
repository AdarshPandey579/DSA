#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>>& image, int i, int j, int m, int n, int sColor, int color, vector<vector<bool>>& visited){
    if(i<0 || i>=m || j<0 || j>=n || visited[i][j] || image[i][j] != sColor) return;
    visited[i][j] = true;
    image[i][j]=color;
    dfs(image, i+1, j, m, n, sColor, color, visited);
    dfs(image, i-1, j, m, n, sColor, color, visited);
    dfs(image, i, j+1, m, n, sColor, color, visited);
    dfs(image, i, j-1, m, n, sColor, color, visited);
}

int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1;
    int sc = 1;
    int color = 2;
    int m = image.size();
    int n = image[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n,false));
    dfs(image, sr, sc, m, n, image[sr][sc], color, visited);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}