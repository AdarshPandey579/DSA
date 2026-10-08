#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {1, 1, 2};
    int u=0, n=nums.size();
    for(int i=0; i<n; i++){
        if(nums[u]!=nums[i]){
            u++;
            nums[u]=nums[i];
        }
    }
    for(int i=0; i<=u; i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}