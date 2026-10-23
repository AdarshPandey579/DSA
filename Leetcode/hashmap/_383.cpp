#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string ransomNote="aa";
    string magazine="ab";
    unordered_map<char, int> freq;
    for(char ch : magazine){
        freq[ch]++;
    }
    for(char ch : ransomNote){
        if(freq.find(ch)==freq.end() || freq[ch]==0){
            cout << "false";
            return false;
        }
        freq[ch]--;
    }
    cout << "true";
    return 0;
}