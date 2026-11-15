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
    vector<vector<int>> grid = {{0, 1, 2, 3, 4}, 
                                {24, 23, 22, 21, 5}, 
                                {12, 13, 14, 15, 16}, 
                                {11, 17, 18, 19, 20}, 
                                {10, 9, 8, 7, 6}
                            };
    int m = grid.size();
    int n = grid[0].size();
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<vector<int>> result(m, vector<int> (n, INT_MAX));
    pq.push({grid[0][0], {0,0}});
    result[0][0] = grid[0][0];
    while(!pq.empty()){
        int currTime = pq.top().first;
        pair<int, int> node = pq.top().second;
        int x = node.first;
        int y = node.second;
        pq.pop();

        if(currTime > result[x][y]) continue;  // stale entry

        if(x==m-1 && y==n-1) {
            cout << result[m-1][n-1] << endl;
            return 0;
        }

        for(auto dir : directions){
            int x_ = x + dir[0];
            int y_ = y + dir[1];
            if(isSafe(x_, y_, m, n)){
                int newTime = max(currTime, grid[x_][y_]);
                if(newTime < result[x_][y_]){
                    result[x_][y_] = newTime;
                    pq.push({newTime, {x_,y_}});
                }
            }
        }
    }
    cout << result[m-1][n-1] << endl;
    return 0;
}