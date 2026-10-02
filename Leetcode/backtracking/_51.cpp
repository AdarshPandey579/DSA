#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n){
    for(int j=0; j<n; j++){
        if(board[row][j]=='Q') return false;
    }
    for(int j=0; j<n; j++){
        if(board[j][col]=='Q') return false;
    }
    for(int i=row,j=col; i>=0 && j>=0; i--,j--){
        if(board[i][j]=='Q') return false;
    }
    for(int i=row,j=col; i>=0 && j<n; i--,j++){
        if(board[i][j]=='Q') return false;
    }
    return true;
}

void nQueen(vector<string> &board, int row, int n, vector<vector<string>> &ans){
    if(row==n){
        ans.push_back(board);
        return;
    }
    for(int j=0; j<n; j++){
        if(isSafe(board, row, j, n)){
            board[row][j]='Q';
            nQueen(board, row+1, n, ans);
            board[row][j]='.';
        }
    }
}

int main(){
    int n=4;
    vector<string> board(n,string(n,'.'));
    vector<vector<string>> ans;
    nQueen(board,0,n,ans);
    for(auto v:ans){
        for(auto s:v){
            cout << s << endl;
        }
        cout << endl;
    }
    return 0;
}

// g++ _51.cpp -o _51;./_51

// .Q..
// ...Q
// Q...
// ..Q.

// ..Q.
// Q...
// ...Q
// .Q..