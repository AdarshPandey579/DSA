#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int n=nums.size();
    if(nums[0]<=nums[n-1]) return nums[0];
    int st=0, end=n-1, mid;
    int ans;
    while(st<=end){
        mid=st+(end-st)/2;
        if(nums[mid]<nums[0]){
            ans=nums[mid];
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}