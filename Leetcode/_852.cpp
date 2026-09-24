#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {0,3,8,9,5,2};
    int st = 1 , end = nums.size()-2;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
            cout<<nums[mid]<<" ";
            return 0;
        }else if (nums[mid]<nums[mid+1]){ // peak is in right side
            st = mid+1;
        }else{ // peak is in left side
            end = mid-1;
        }
    }
    return 0;
}