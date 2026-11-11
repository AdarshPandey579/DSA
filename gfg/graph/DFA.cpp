#include<iostream>
#include<vector>
using namespace std;

vector<int> ans;
void dfs(vector<vector<int>>& adj, int v, vector<bool>& isVisited){
    isVisited[v] = true;
    ans.push_back(v);
    for(int neighbour : adj[v]){
        if(isVisited[neighbour]!=true) dfs(adj, neighbour, isVisited);
    }
}

int main(){
    vector<vector<int>> adj = {{2,3,1},{0},{0,4},{0},{2}};
    vector<bool> isVisited(adj.size(), false);
    dfs(adj, 0, isVisited);
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    return 0;
}