#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    unordered_map<int, int> mp;
    mp[0]=1;
    int n=nums.size(), count=0, prefixSum=0, rem=0;
    for(int i=0; i<n; i++){
        prefixSum+=nums[i];
        rem=prefixSum%k;
        if(rem<0) rem+=k;
        if(mp.find(rem)!=mp.end()){
            count+=mp[rem];
        }
        mp[rem]++;
    }
    cout << count;
    return 0;
}