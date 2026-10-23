#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    string s = "abccccdd";
    unordered_map<char,int> freq;
    bool odd = false;
    int length=0;
    for(char ch : s){
        freq[ch]++;
    }
    for(auto i : freq){
        if(i.second&1){
            odd = true;
            length+=(i.second-1);
        }else{
            length+=i.second;
        }
    }
    if(odd == true) length+=1;
    cout << length;
    return 0;
}