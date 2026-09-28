#include<iostream>
using namespace std;

int main() {
    int x=239032;
    string s = to_string(x);
    int st=0 , end=s.length()-1;
    while(st<end){
        if(s[st]!=s[end]){
            cout << false;
            return 0;
        }else{
            st++;
            end--;
        }
    }
    cout << true;
    return 0;
}