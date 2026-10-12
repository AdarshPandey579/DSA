#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> nums = {0,1,1,1,1,1,0,0,0};
    unordered_map<int,int> mp;
    mp[0]=-1;
    int diff=0, length=0, n=nums.size();
    for(int i=0; i<n; i++){
        if(nums[i]==0) diff++;
        else diff--;
        if(mp.find(diff)==mp.end()){
            mp[diff]=i;
        }
        length=max(length,i-mp[diff]);
    }
    cout << length;
    return 0;
}

//g++ _525.cpp -o _525;./_525 