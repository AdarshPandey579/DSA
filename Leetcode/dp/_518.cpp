#include <bits/stdc++.h>
using namespace std;

int func(int i, int amount, vector<int>& coins, int n, vector<vector<int>>& dp){
    if(amount == 0) return 1;
    if(i == n) return 0;

    if(dp[i][amount] != -1) return dp[i][amount];

    int take = coins[i] <= amount ? func(i, amount - coins[i], coins, n, dp) : 0;
    int skip = func(i+1, amount, coins, n, dp);

    return dp[i][amount] = take + skip;
}

int main(){
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1,-1));
    cout << func(0, amount, coins, n, dp) << endl;
    return 0;
}