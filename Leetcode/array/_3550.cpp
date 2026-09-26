#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {1,3,2};
    for(int i=0;i<nums.size();i++){
        int sum = 0;
        int num = nums[i];
        while(num>0){
            sum += num%10;
            num /= 10;
        }
        if(sum==i){
            cout<<nums[i]<<" ";
            return 0;
        }
    }
    cout<<-1;
    return 0;
}