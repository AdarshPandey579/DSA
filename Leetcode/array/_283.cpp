#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {0, 1, 0, 3, 12};
    int z=0, n=nums.size();
    for (int nz=0; nz<n; nz++){
        if(nums[nz]!=0){
            swap(nums[z],nums[nz]);
            z++;
        }
    }
    for(int num: nums){
        cout<<num<<" ";
    }
    return 0;
}