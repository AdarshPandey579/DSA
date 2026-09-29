#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> grid = {{1,3},{2,2}};
    vector<int> ans;
    int n = grid.size();
    vector<int> freq(n*n + 1 , 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            freq[grid[i][j]]++;
        }
    }
    int repeated = -1;
    int missing = -1;
    for (int i = 1; i <= n * n; i++) {
        if (freq[i] == 2) {
            ans.push_back(i);
        }
        if (freq[i] == 0) {
            ans.push_back(i);
        }
    }
    for(int num : ans) cout<<num<<" ";
    return 0;
}