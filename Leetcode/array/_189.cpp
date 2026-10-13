#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums={1,2,3,4,5,6,7};
    int k=3;
    if (nums.empty()) return 0;
    int n=nums.size();
    k=k%n;
    vector<int> ans(n,0);
    for(int i=0;i<k;i++){
        ans[i]=nums[n-k+i];
    }
    for(int i=k;i<n;i++){
        ans[i]=nums[i-k];
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    return 0;
}

//g++ _189.cpp -o _189;./_189   