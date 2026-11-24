#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> matrix = {{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
    int n = matrix.size();
    vector<int> vertex(n, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 1) vertex[j]++;
        }
    }
    for(int node : vertex) {
        cout << node << ' ';
    }
    return 0;
}