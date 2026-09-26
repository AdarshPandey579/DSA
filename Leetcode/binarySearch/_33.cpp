#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums={4,5,6,7,0,1,2};
    int target=0;
    int st = 0, end = nums.size()-1;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(nums[mid]==target){
            cout<<mid;
            return 0;
        }
        if(nums[st]<=nums[mid]){ // left side is sorted
            if(nums[st]<=target && target<=nums[mid]){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }else{ // right side is sorted
            if(nums[mid]<=target && target<=nums[end]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
    }
    return -1;
}