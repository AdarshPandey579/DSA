#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums={1,2,3,4};
    int n=nums.size(), sum=0;
    for(int i=0;i<n;i++){
        if(n%(i+1)==0) sum+=nums[i]*nums[i];
    }
    cout << sum;
    return 0;
}

//g++ _2778.cpp -o _2778;./_2778