#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "abcde", goal = "cdeab";
    if(s.size() != goal.size()) return false;
    if(s == goal) return true;
    int n = s.size();
    for (int i=0; i<n; i++){
        char ch = s.front();
        s.erase(0,1);
        s.push_back(ch);
        if(s==goal){
            cout << "true" << endl;
            return true;
        }
    }
    cout << "false" << endl;
    return false;
}