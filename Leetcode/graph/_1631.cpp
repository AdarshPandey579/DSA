#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
typedef pair<int, pair<int , int>> P;
bool isSafe(int x, int y, int m, int n){
    return x>=0 && x<m && y>=0 && y<n;
}

int main(){
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    int m = heights.size();
    int n = heights[0].size();
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<vector<int>> result(m, vector<int> (n, INT_MAX));
    pq.push({0, {0,0}});
    result[0][0] = 0;
    while(!pq.empty()){
        int currEffort = pq.top().first;
        pair<int, int> node = pq.top().second;
        int x = node.first;
        int y = node.second;
        pq.pop();
        if(currEffort > result[x][y]) continue;
        if(x==m-1 && y==n-1){
            cout << result[m-1][n-1] << endl;
            return 0;
        }
        for(auto dir : directions){
            int x_ = x + dir[0];
            int y_ = y + dir[1];
            if(isSafe(x_, y_, m, n)){
                int absDiff = abs(heights[x][y] - heights[x_][y_]);
                int newEffort = max(currEffort, absDiff);
                if(newEffort < result[x_][y_]){
                    result[x_][y_] = newEffort;
                    pq.push({newEffort, {x_,y_}});
                }
            }
        }
    }
    cout << result[m-1][n-1] << endl;
    return 0;
}