#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main(){
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto edge : times){
        int s = edge[0];
        int d = edge[1];
        int w = edge[2];
        adj[s].push_back({d,w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n+1 , INT_MAX);
    pq.push({0,k});
    dist[k]=0;
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        int d = p.first;
        int node = p.second;
        if(d > dist[node]) continue;
        for(auto item : adj[node]){
            int neighbour = item.first;
            int time = item.second;
            if(d+time < dist[neighbour]){
                pq.push({d+time, neighbour});
                dist[neighbour] = d+time;
            }
        }
    }

    // find the maximum time taken to reach any node
    int ans=-1;
    for(int i=1; i<=n; i++) ans = max(ans, dist[i]);

    // handle unreachable nodes
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}