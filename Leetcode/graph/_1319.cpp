#include<iostream>
#include<vector>
using namespace std;

vector<int> Parent;
vector<int> Rank;

int find(int x){
    if(x == Parent[x]) return x;
    return Parent[x] = find(Parent[x]);
}

void Union(int x, int y){
    int parent_x = find(x);
    int parent_y = find(y);
    if(parent_x == parent_y) return;
    if(Rank[parent_x] < Rank[parent_y]) Parent[parent_x] = parent_y;
    else if(Rank[parent_x] > Rank[parent_y]) Parent[parent_y] = parent_x;
    else{
        Parent[parent_y] = parent_x;
        Rank[parent_x]++;
    }
}

int main(){
    int n = 6;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
    Parent.assign(n, 0);
    Rank.assign(n, 0);
    for(int i=0; i<n; i++) Parent[i] = i;
    int components = n;
    for(auto edge : connections){
        if(find(edge[0]) != find(edge[1])){
            Union(edge[0], edge[1]);
            components--;
        }
    }
    cout <<  components - 1 << endl;
    return 0;
}