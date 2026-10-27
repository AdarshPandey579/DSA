#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    // int target = 100;
    // int target = 19;
    int m=matrix.size();
    int n=matrix[0].size();
    int st=0, end=m-1, mid, row=m;
    while(st<=end){
        mid=st+(end-st)/2;
        if(matrix[mid][0]<=target){
            row=mid;
            st=mid+1;
        }else{
            end=mid-1;
        }
    }

    if(row==m){
        cout << false << endl;
        return 0;
    }

    st=0, end=n-1;
    while(st<=end){
        mid=st+(end-st)/2;
        if(matrix[row][mid]==target){
             cout << true << endl;
             return 0;
        }
        else if(matrix[row][mid]<=target) st=mid+1;
        else end=mid-1;
    }
    cout << false << endl;
    return 0;
}