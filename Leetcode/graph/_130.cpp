#include<iostream>
#include<vector>
using namespace std;

void DFA(int i, int j, vector<vector<char>>& board, int m, int n){
    if(i<0 || i>=m || j<0 || j>=n || board[i][j]!='O') return;
    board[i][j] = '$';
    DFA(i-1, j, board, m, n);
    DFA(i+1, j, board, m, n);
    DFA(i, j+1, board, m, n);
    DFA(i, j-1, board, m, n);
}

int main(){
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    int m = board.size();
    int n = board[0].size();
    for(int j=0; j<n; j++){
        DFA(0, j, board, m, n);
        DFA(m-1, j, board, m, n);
    }
    for(int i=0; i<m; i++){
        DFA(i, 0, board, m, n);
        DFA(i, n-1, board, m, n);
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]=='$') board[i][j]='O';
            else board[i][j]='X';
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}