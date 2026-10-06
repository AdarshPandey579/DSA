#include<iostream>
#include<vector>
using namespace std;

int BS(vector<int>& nums, int target, int s, int e){
    if(s<=e){
        int mid=s+(e-s)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]<target) return BS(nums, target, mid+1, e);
        else return BS(nums, target, s,mid-1);
    }
    return -1;
}

int main(){
    vector<int> nums={-1,0,3,5,9,12};
    int target=9;
    int s=0;
    int e=nums.size()-1;
    cout << BS(nums,target,s,e);
}