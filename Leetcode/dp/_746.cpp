#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int, int> dp;
int func(vector<int>& cost, int n){
    if(n<=1) return 0;
    if(dp.find(n) != dp.end()) return dp[n];
    int ans = min(func(cost, n-1) + cost[n-1], func(cost, n-2) + cost[n-2]);
    dp[n] = ans;
    return ans;
}

int main(){
    vector<int> cost = {10, 15, 20};
    int n = cost.size();
    cout << func(cost, n) << endl;
    return 0;
}