#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {1,5,11,5};
    int sum = 0;
    for(int num : nums) sum+=num;
    if(sum%2 != 0) {
        cout << false << endl;
        return 0;
    }
    int target = sum/2;
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    dp[n][0] = 1;
    for(int i=n-1; i>=0; i--){
        for(int s=0; s<=target; s++){
            int accept = nums[i]<=s ? dp[i+1][s-nums[i]] : 0;
            int reject = dp[i+1][s];
            dp[i][s] = accept || reject;
        }
    }
    cout << dp[0][target] << endl;
    return 0;
}