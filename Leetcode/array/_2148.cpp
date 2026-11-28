#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {-3, 3, 3, 90};
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int &num : nums){
        mini = min(mini, num);
        maxi = max(maxi, num);
    }
    int ans = 0;
    for(int &num : nums){
        if(num == mini || num == maxi) continue;
        ans++;
    }
    cout << ans;
    return 0;
}