#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int main(){
    string s = "(ed(et(oc))el)";
    stack<string> st;
    string curr = "";

    for (char ch : s) {

        if (ch == '(') {
            st.push(curr);
            curr = "";
        }
        else if (ch == ')') {
            reverse(curr.begin(), curr.end());

            curr = st.top() + curr;
            st.pop();
        }
        else {
            curr += ch;
        }
    }

    cout<< curr;
    return 0;
}