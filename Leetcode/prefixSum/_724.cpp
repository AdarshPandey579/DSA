#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int pref=0, suf=0, n=nums.size();
    for(int i=0;i<n;i++){
        suf+=nums[i];
    }
    for(int i=0;i<n;i++){
        suf-=nums[i];
        if(pref==suf){
            cout<<i;
            return 0;
        }
        pref+=nums[i];
    }
    cout << -1;
    return 0;
}