#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums={1,2,3,4};
    int prefix=0;
    for(int i=0; i<nums.size(); i++){
        nums[i]+=prefix;
        prefix=nums[i];
    }
    for(int i : nums){
        cout<<i<<" ";
    }
    return 0;
}