#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "000001";
    int Change = 0 ;
    int n = s.size();
    for(int i=0; i<n; i+=2){
        if(s[i] != s[i+1]) Change++;
    }
    cout << Change << endl;
    return 0;
}