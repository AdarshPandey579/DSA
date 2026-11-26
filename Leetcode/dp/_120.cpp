#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int n = triangle.size();
    vector<vector<int>> dp(n);
    dp[n-1] = triangle[n-1];
    for(int i=n-2; i>=0; i--){
        dp[i].resize(i+1);
        for(int j=0; j<=i ; j++){
            dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    cout << dp[0][0];
    return 0;
}