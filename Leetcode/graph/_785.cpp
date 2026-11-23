#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// DFS
bool DFS(int v, vector<vector<int>>& graph, int color, vector<int>& colored){
    colored[v] = color;
    for(int neighbour : graph[v]){
        if(colored[neighbour]==-1){
            if(!DFS(neighbour, graph, !color, colored)) return false;
        }
        else if(colored[neighbour] == color) return false;
    }
    return true;
}

// BFS
bool BFS(int v, vector<vector<int>>& graph, vector<int>& colored){
    colored[v] = 0;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int neighbour : graph[node]){
            if(colored[neighbour]==-1){
                colored[neighbour] = 1 - colored[node];
                q.push(neighbour);
            }
            else if(colored[neighbour] == colored[node]) return false;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2},{5},{4}};
    /*
    Graph representation:
        0-----1
        |     |
        |     |
        3-----2

        4-----5
    */
    vector<int> colored(graph.size(), -1);
    for(int i=0; i<graph.size(); i++){
        if(colored[i]==-1){
            if(!DFS(i, graph, 0, colored)){
                cout<<"Not Bipartite"<<endl;
                return 0;
            }
        }
    }
    cout<<"Bipartite"<<endl;
    return 0;
}