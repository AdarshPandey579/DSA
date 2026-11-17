#include <bits/stdc++.h>
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

// Tabulation
int rob(vector<int>& nums, int start, int end){
    dp.clear();
    dp[start] = nums[start];
    dp[start+1] = max(nums[start], nums[start+1]);
    for(int i= start + 2; i<=end; i++){
        int accept = nums[i] + dp[i-2];
        int skip = dp[i-1];
        dp[i] = max(accept, skip);
    }
    return dp[end];
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

    int _0thIndex = rob(nums, 0, n-2);
    int _1thIndex = rob(nums, 1, n-1);
    cout << max(_0thIndex, _1thIndex) << endl;
    return 0;
}