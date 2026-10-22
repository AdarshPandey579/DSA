#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){
    vector<int> t={73,74,75,71,69,72,76,73};
    stack<int> st;
    vector<int> ans(t.size(), 0);
    int n=t.size();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && t[st.top()]<=t[i]) st.pop();
        if(!st.empty()) ans[i]=st.top()-i;
        else ans[i]=0;
        st.push(i);
    }
    for(int num : ans){
        cout<<num<<" ";
    }
    return 0;
}