#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1, 4, 7, 8, 5};
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int a = nums[n-1] - nums[2];
    int b = nums[n-3] - nums[0];
    int c = nums[n-2] - nums[1];
    cout << min(a,min(b,c)) << endl;
    return 0;
}