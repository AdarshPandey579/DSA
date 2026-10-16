#include<iostream>
#include<stack>
using namespace std;

int main(){
    string s = "{[()]}";
    stack<char> st;
    for(char ch : s){
        if( ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }else{
            if(st.empty()) return false;
            if(ch==')' && st.top()=='('){
                st.pop();
            }else if(ch==']' && st.top()=='['){
                st.pop();
            }else if(ch=='}' && st.top()=='{'){
                st.pop();
            }else{
                return false;
            }
        }
    }
    cout << st.empty();
    return 0;
}

//g++ _20.cpp -o _20;./_20