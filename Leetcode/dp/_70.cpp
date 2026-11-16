#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<int, int> dp;
int climbStairs(int n) {
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp.find(n) != dp.end()) return dp[n];
    int ans = climbStairs(n-1) + climbStairs(n-2);
    dp[n] = ans;
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;
    cout << climbStairs(n) << endl;
    return 0;
}