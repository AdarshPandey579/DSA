#include <bits/stdc++.h>
using namespace std;

// Recursive + Memoization
// int lengthOfLIS(int i, int p, vector<int>& nums, int& n, vector<vector<int>>& dp) {
//     if(i == n) return 0;
//     if(p != -1 && dp[i][p] != -1) return dp[i][p];
//     int accept = (p == -1 ||  nums[p]<nums[i]) ? 1 + lengthOfLIS(i+1, i, nums, n, dp) : 0;
//     int reject = lengthOfLIS(i+1, p, nums, n, dp);
//     if (p != -1) return dp[i][p] = max(accept, reject);
//     return max(accept , reject);
// }

// Binary Search + DP
int LB(vector<int>& arr, int num){
    int st = 0;
    int end = arr.size() - 1;
    int res = -1;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(arr[mid] >= num) {
            end = mid-1;
            res = mid;
        }else{
            st = mid+1;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = nums.size();
    vector<int> arr;
    for(int i=0; i<n; i++){
        int idx = LB(arr, nums[i]);
        if(idx == -1) arr.push_back(nums[i]);
        else arr[idx] = nums[i];
    }
    cout << arr.size() << endl;
    return 0;
}