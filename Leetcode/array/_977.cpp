#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    // vector<int> nums={-5,-3,-2,-1};
    vector<int> nums={-4,-1,0,3,10};
    int neg=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<0)neg++;
        nums[i]*=nums[i];
    }
    if(neg!=0){
        reverse(nums.begin(),nums.begin()+neg);
        if(neg==nums.size()){
            return 0;
        }
    }
    vector<int> ans(nums.size());
    int i=0, j=neg, k=0;
    while(i<neg && j<nums.size()){
        if(nums[i]>nums[j]) ans[k++]=nums[j++];
        else ans[k++]=nums[i++];
    }
    while(i<neg) ans[k++]=nums[i++];
    while(j<nums.size()) ans[k++]=nums[j++];
    for(int i=0;i<nums.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}