#include<iostream>
#include<vector>
using namespace std;

bool validK(vector<vector<int>>& mat, int m, int n, int k, int mid){
    int row=m-1, col=0, totalK=0;
    while(row>=0 && col<n){
        if(mat[row][col]>mid) row--;
        else{
            totalK+=row+1;
            col++;
        }
    }
    if(totalK < k) return false;
    return true;
}
    

int main(){
    vector<vector<int>> mat = {{1,5,9},{10,11,13},{12,13,15}};
    int k=8;
    int m=mat.size();
    int n=mat[0].size();
    int st=mat[0][0];
    int end=mat[m-1][n-1];
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(validK(mat, m, n, k, mid)){
            ans=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}