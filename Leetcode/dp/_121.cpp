#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    vector<int> prices={7,1,5,3,6,4};
    int n=prices.size();
    int maxProfit=0, low=INT_MAX;
    for(int i=0; i<n; i++){
        low=min(low,prices[i]);
        maxProfit=max(maxProfit,prices[i]-low);
    }
    cout << maxProfit;
    return 0;
}