#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> dp;
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
    if(n == 1) return nums[0];
    if(n == 2) return max(nums[0], nums[1]);
    int _0thIndex = func(nums, 0, n-1);
    dp.clear();
    int _1thIndex = func(nums, 1, n);
    cout << max(_0thIndex, _1thIndex) << endl;
    return 0;
}