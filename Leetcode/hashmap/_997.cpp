#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n = 3;
    vector<vector<int>> trust = {{1, 3}, {2, 3}};
    vector<int> score(n+1, 0);
    for(auto &v : trust) {
        score[v[0]]--;
        score[v[1]]++;
    }
    for(int i=1; i<=n; i++) {
        if(score[i] == n-1) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}