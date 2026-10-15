#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {1,2,1};
    unordered_map<int,int> mp;
    int count=0, i=0, n=nums.size();
    while(i<n){
        int j=i;
        while(j<n){
            if(mp.find(nums[j])==mp.end()){
                mp[nums[j]]=1;
            }
            int m = mp.size();
            count+=(m*m);
            j++;
        }
        mp.clear();
        i++;
    }
    cout << count;
    return 0;
}

// g++ _2913.cpp -o _2913;./_2913