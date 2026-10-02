 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;

void solve(int i, int j, int n, vector<vector<int>>& maze, vector<string> &ans, string path){
    if(i<0 || j<0 || i>=n || j>=n || maze[i][j]==0){
        return;
    }
    if(i==n-1 && j==n-1){
        ans.push_back(path);
        return;
    }
    maze[i][j]=0;

    path.push_back('D');
    solve(i+1,j,n,maze,ans,path);
    path.pop_back();

    path.push_back('U');
    solve(i-1,j,n,maze,ans,path);
    path.pop_back();

    path.push_back('R');
    solve(i,j+1,n,maze,ans,path);
    path.pop_back();

    path.push_back('L');
    solve(i,j-1,n,maze,ans,path);
    path.pop_back();

    maze[i][j]=1;
}

int main(){
    int n = 4;
    vector<vector<int>> maze={{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans;
    string path="";
    solve(0,0,n,maze,ans,path);
    sort(ans.begin(),ans.end());
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}