#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int n = coins.size();
    vector<int> curr(amount+1,1e9);
    vector<int> next(amount+1,1e9);

    next[0] = 0;
    for(int i=n-1; i>=0; i--){
        for(int a=0; a<=amount; a++){
            int accept = coins[i] <= a ? 1 + curr[a-coins[i]] : 1e9;
            int reject = next[a];
            curr[a] = min(accept, reject);
        }
        next = curr;
    }
    cout << (curr[amount] >= 1e9 ? -1 : curr[amount]) << endl;
    return 0;
}

// Time Complexity: O(n*amount)
// Space Complexity: O(amount)