#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    string s="abbaca",result="";
    stack<char> st;
    for(char ch : s){
        if(!st.empty() && st.top()==ch) st.pop();
        else st.push(ch);
    }
    while(!st.empty()){
        result=st.top()+result;
        st.pop();
    }
    cout<<result;
    return 0;
}