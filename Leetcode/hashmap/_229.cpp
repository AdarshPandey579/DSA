#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> nums = {3, 2, 3};
    int n = nums.size();
    int l = n/3;
    vector<int> ans;
    unordered_map<int, int> freq;
    for(int num : nums) freq[num]++;
    for(auto item : freq){
        int num = item.first;
        int frq = item.second;
        if(frq > l) ans.push_back(num);
    }
    for(int num : ans) cout << num << ' ';
    return 0;
}