#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> nums={1,-1,2,-2,3,-3};
    int n=nums.size();
    for (int i=0;i<n;i++){
        nums[i]*=nums[i];
    }
    sort(nums.begin(),nums.end());
    int mid=n/2;
    long long ans=0;
    for(int i=0;i<mid;i++){
        ans-=nums[i];
    }
    for(int i=mid;i<n;i++){
        ans+=nums[i];
    }
    cout << ans;
    return 0;
}