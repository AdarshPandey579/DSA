#include<iostream>
#include<vector>
#include<unordered_map>
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
    cout << func(nums, 0, n) << endl;
    return 0;
}