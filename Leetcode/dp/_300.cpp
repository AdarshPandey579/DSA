#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(int i, int p, vector<int>& nums, int& n, vector<vector<int>>& dp) {
    if(i == n) return 0;
    if(p != -1 && dp[i][p] != -1) return dp[i][p];
    int accept = (p == -1 ||  nums[p]<nums[i]) ? 1 + lengthOfLIS(i+1, i, nums, n, dp) : 0;
    int reject = lengthOfLIS(i+1, p, nums, n, dp);
    if (p != -1) return dp[i][p] = max(accept, reject);
    return max(accept , reject);
}

int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << lengthOfLIS(0, -1, nums, n, dp) << endl;
    return 0;
}