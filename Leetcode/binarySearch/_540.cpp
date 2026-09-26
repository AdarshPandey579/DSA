#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums={1,1,2,3,3,4,4,8,8}; // mid is even i.e. 4
    // nums={3,3,7,7,10,11,11}; // mid is odd i.e. 3
    // nums={1};
    int st=0 , n=nums.size() , end=n-1;
    if(n==1){ // edge case 1
        cout<<nums[0]<<endl;
        return 0;
    }
    while(st<=end){
        int mid = st+(end-st)/2;
        if(mid==0 && nums[0]!=nums[1]){ // edge case 2
            cout<<nums[0]<<endl;
            return 0;
        }
        if(mid==n-1 && nums[n-2]!=nums[n-1]){ // edge case 3
            cout<<nums[n-1]<<endl;
            return 0; 
        }
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
            cout<<nums[mid]<<endl;
            return 0;
        }
        if(mid%2==0){
            if(nums[mid]==nums[mid-1]){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }else{
            if(nums[mid]==nums[mid-1]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
    }
    return 0;
}