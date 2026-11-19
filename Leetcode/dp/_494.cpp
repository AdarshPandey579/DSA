#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int sum = 0;
    for(int num : nums) sum+=num;
    if(sum < abs(target)) {
        cout << 0 << endl;
        return 0;
    }
    if((sum + target) % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    int n = nums.size();
    int subsetSum = (sum + target) / 2;
    vector<vector<int>> dp(n+1, vector<int>(subsetSum+1, 0));
    dp[n][0] = 1;
    for(int i=n-1; i>=0; i--){
        for(int s=0; s<=subsetSum; s++){
            int accept = nums[i] <= s ? dp[i+1][s-nums[i]] : 0;
            int reject = dp[i+1][s];
            dp[i][s] = accept + reject;
        }
    }
    cout << dp[0][subsetSum] << endl;
    return 0;
}