#include<iostream>
#include<vector>
using namespace std;

void DFA(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    for(auto neighbour : adj[v]){
        if(!visited[neighbour]) DFA(neighbour, adj, visited);
    }
}

int main(){
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    /*
        0---1   2
    */
    int n = isConnected.size();
    vector<vector<int>> adj(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            if(isConnected[i][j]==1) adj[i].push_back(j);
        }
    }
    vector<bool> visited(n, false);
    int provinces = 0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            DFA(i, adj, visited);
            provinces++;
        }
    }
    cout << provinces << endl;
    return 0;
}