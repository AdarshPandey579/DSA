#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    vector<int> nums = {4, 2, 4};
    unordered_map<long long, int> freq;
    long long sum = nums[0] + nums[1];
    freq[sum]++;
    for(int i=2; i<nums.size(); i++){
        sum += (nums[i] - nums[i-2]);
        if(freq.find(sum) != freq.end()) {
            cout << true << endl;
            return 0;
        }
        freq[sum]++;
    }
    cout << false << endl;
    return 0;
}