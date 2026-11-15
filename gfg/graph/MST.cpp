#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    vector<vector<vector<int>>> adj = {{{1, 5}, {2, 1}}, {{0, 5}, {2, 3}}, {{0, 1}, {1, 3}}};
    int n = adj.size();
    int sum = 0;
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        int weight = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(visited[v]) continue;
        visited[v] = true;
        sum += weight;
        for(auto edge : adj[v]){
            int neighbour = edge[0];
            int weight = edge[1];
            if(!visited[neighbour]) pq.push({weight, neighbour});
        }
    }
    cout << sum << endl;
    return 0;
}