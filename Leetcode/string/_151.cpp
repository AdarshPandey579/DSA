#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s="the sky is blue";
    reverse(s.begin(),s.end());
    string ans="";
    int n=s.length();
    for(int i=0; i<n; i++){
        string word="";
        while(i<n && s[i]!=' '){
            word+=s[i];
            i++;
        }
        if(word.length()!=0){
            reverse(word.begin(),word.end());
            ans+=" "+word;
        }
    }
    cout<< ans.substr(1);
    return 0;
}