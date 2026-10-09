#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {3,4,5,1,2};
    int count = 0, n = nums.size();
    for(int i=1; i<=n-1; i++){
        if(nums[i-1]>nums[i]) count++;
    }
    if(count==0){
        cout<< true; 
        return 0;
    }
    else if(count==1){
        if(nums[n-1]<=nums[0]){
            cout<< true; 
            return 0;
        }
    }
    cout<< false;
    return 0;
}