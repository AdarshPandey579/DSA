#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s = "daabcbaabcbc", part="abc", st;
    int n = part.size();
    for (char ch : s) {
        st.push_back(ch);
        if (st.size() >= n) {
            bool match = true;
            for (int i = 0; i < n; i++) {
                if (st[st.size() - n + i] != part[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                st.resize(st.size() - n);
            }
        }
    }
    cout<< st;
    return 0;
}