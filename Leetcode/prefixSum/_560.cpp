#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> nums = {1, 1, 1};
    int k = 2;
    unordered_map<int , int> mp;
    mp[0]=1;
    int prefixSum=0, n=nums.size(), count=0;
    for(int i=0; i<n; i++){
        prefixSum+=nums[i];
        int diff=prefixSum-k;
        if(mp.find(diff)!=mp.end()){
            count+=mp[diff];
        }
        mp[prefixSum]++;
    }
    cout << count;
    return 0;
}

//g++ _560.cpp -o _560;./_560