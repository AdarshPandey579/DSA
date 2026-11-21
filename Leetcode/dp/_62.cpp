#include<iostream>
#include<vector>
using namespace std;

int uniquePaths(int i, int j, int m, int n, vector<vector<int>>& dp) {
    if(i==m-1 && j==n-1) return 1;
    if(i==m || j==n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int right = uniquePaths(i, j+1, m, n, dp);
    int down = uniquePaths(i+1, j, m, n, dp);
    return dp[i][j] = right + down;
}

int main(){
    int m = 3;
    int n = 7;
    vector<vector<int>> dp(m, vector<int>(n,-1));
    cout << uniquePaths(0, 0, m, n, dp) << endl;
    return 0;
}