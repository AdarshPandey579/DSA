#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string s = "anagram";
    string t = "nagaram";
    if(s.size() != t.size()){
        cout << false << endl;
        return 0;
    }
    unordered_map<char,int> freq;
    for(char ch : s){
        freq[ch]++;
    }
    for(char ch : t){
        if(freq.find(ch)==freq.end() || freq[ch]==0){
            cout << false << endl;
            return 0;
        }
        freq[ch]--;
    }
    cout << true << endl;
    return 0;
}