#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int main(){
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
    dp[m][n-1] = 0;
    dp[m-1][n] = 0;

    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}