#include<iostream>
using namespace std;

int main(){
    string str = "leet**cod*e";
    string st = "";
    for(char ch : str){
        if(ch == '*'){
            st.pop_back();
            continue;
        }
        st.push_back(ch);
    }
    cout << st;
    return 0;
}