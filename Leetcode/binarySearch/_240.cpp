#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> mat = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 11;
    int m=mat.size();
    int n=mat[0].size();
    int row=m-1, col=0;
    while(row>=0 && col<n){
        if(mat[row][col]==target){
            cout << true << endl;
            return 0;
        } 
        else if(mat[row][col]>target) row--;
        else col++;
    }
    cout << false << endl;
    return 0;

}