#include<iostream>
#include<vector>
using namespace std;

// Recursion + Memoization
// int uniquePaths(int i, int j, int m, int n, vector<vector<int>>& dp) {
//     if(i==m-1 && j==n-1) return 1;
//     if(i==m || j==n) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
//     int right = uniquePaths(i, j+1, m, n, dp);
//     int down = uniquePaths(i+1, j, m, n, dp);
//     return dp[i][j] = right + down;
// }

// Tabulation
int main(){
    int m = 3;
    int n = 7;
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));
    dp[m-1][n-1] = 1;
    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(i==m-1 && j==n-1) continue;
            dp[i][j] = dp[i+1][j] + dp[i][j+1];
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}