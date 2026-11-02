#include<bits/stdc++.h>
using namespace std;

void fun(int open, int close, int n, string& tmp, vector<string>& ans){
    if(open==n && close==n){
        ans.push_back(tmp);
        return;
    }
    if(open<n){
        tmp.push_back('(');
        fun(open+1, close, n, tmp, ans);
        tmp.pop_back();
    }
    if(close<open){
        tmp.push_back(')');
        fun(open, close+1, n, tmp, ans);
        tmp.pop_back();
    }
    return;
}

int main(){
    int open=0;
    int close=0;
    int n=3;
    string tmp="";
    vector<string> ans;
    fun(open, close, n, tmp, ans);
    for(auto i: ans){
        cout<<i<<endl;
    }
    return 0;
}