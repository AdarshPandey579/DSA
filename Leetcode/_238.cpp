#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {1, 2, 3, 4};
    int size = nums.size();
    vector<int> ans(size, 1);
    for(int i=1; i<size; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }
    int right = 1;
    for(int i=size-2; i>=0; i--){
        right *= nums[i+1];
        ans[i] *= right;
    }
    for(int num : ans){
        cout << num << " ";
    }
}