#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string s="abca";
    unordered_map<char,int> mp;
    for(char ch : s){
        mp[ch]++;
    }
    for(int i=0; i<s.size(); i++){
        if(mp[s[i]]==1){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}