#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = arr.size();
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    
    for(int s=0; s<=sum; s++) dp[n][s] = s==0 ;
    
    for(int i=n-1; i>=0; i--){
        for(int s=0; s<=sum; s++){
            bool accept = arr[i] <= s ? dp[i+1][s-arr[i]] : false;
            bool reject = dp[i+1][s];
            dp[i][s] = accept || reject;
        }
    }
    cout << dp[0][sum] << endl;
    return 0;
}