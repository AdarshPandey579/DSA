#include <bits/stdc++.h>
using namespace std;

int main(){
    int W = 4;
    vector<int> wt = {1, 3, 4};
    vector<int> val = {15, 20, 30};
    int n = val.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for(int i=n-1; i>=0; i--){
        for(int w=0; w<=W; w++){
            int accept = wt[i] <= w ? val[i] + dp[i+1][w-wt[i]] : 0;
            int reject = dp[i+1][w];
            dp[i][w] = max(accept, reject);
        }
    }
    cout << dp[0][W] << endl;
    return 0;
}