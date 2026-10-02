// Soduku solver
#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<char>> &grid, int row, int col, char dig){
    for(int i=0; i<9; i++){
        if(grid[row][i]==dig) return false;
        if(grid[i][col]==dig) return false;
    }
    int sr=(row/3)*3;
    int sc=(col/3)*3;
    for(int i=sr; i<=sr+2; i++){
        for (int j=sc; j<=sc+2; j++){
            if(grid[i][j]==dig) return false;
        }
    }
    return true;
}

bool SS(vector<vector<char>> &grid){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(grid[i][j]!='.'){
                continue;
            }
            for(char dig='1'; dig<='9'; dig++){
                if(isSafe(grid, i, j, dig)){
                    grid[i][j]=dig;
                    if(SS(grid)) return true;
                    grid[i][j]='.';
                }
            }
            return false;
        }
    }
    return true;
}

int main(){
    vector<vector<char>> grid={{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};
    SS(grid);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// g++ _37.cpp -o _37;./_37