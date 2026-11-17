#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int, int> dp;
// Recursion + Memoization
int func(vector<int>& nums, int i, int n){
    if(i>=n) return 0;
    if(dp.find(i) != dp.end()) return dp[i];
    int accept = nums[i] + func(nums, i+2, n);
    int skip = func(nums, i+1, n);
    dp[i] = max(accept, skip);
    return dp[i];
}

int main(){
    vector<int> nums = {2,7,9,3,1};
    int n = nums.size();
    if(n == 1) {
        cout << nums[0] << endl;
        return 0;
    }
    if(n == 2) {
        cout << max(nums[0], nums[1]) << endl;
        return 0;
    }

    // Tabulation
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i=2; i<n; i++){
        int accept = nums[i] + dp[i-2];
        int skip = dp[i-1];
        dp[i] = max(accept, skip);
    }
    cout << dp[n-1] << endl;
    return 0;
}