#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization
// int func(int i, int amount, vector<int>& coins, int n, vector<vector<int>>& dp){
//     if(amount == 0) return 1;
//     if(i == n) return 0;

//     if(dp[i][amount] != -1) return dp[i][amount];

//     int take = coins[i] <= amount ? func(i, amount - coins[i], coins, n, dp) : 0;
//     int skip = func(i+1, amount, coins, n, dp);

//     return dp[i][amount] = take + skip;
// }


// Tabulation
int main(){
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    int n = coins.size();
    vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(amount+1,0));
    dp[n][0] = 1;
    for(int i=n-1; i>=0; i--){
        for(int a=0; a<=amount; a++){
            unsigned long long accept = coins[i] <= a ? dp[i][a-coins[i]] : 0;
            unsigned long long reject = dp[i+1][a];
            dp[i][a] = accept + reject;
        }
    }
    cout << dp[0][amount] << endl;
    return 0;
}