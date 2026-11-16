#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int, int> dp;
int tribonacci(int n) {
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    if(dp.find(n) != dp.end()) return dp[n];
    int ans = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    dp[n] = ans;
    return ans;
}

int main(){
    int n = 25;
    cout << tribonacci(n) << endl;
    return 0;
}