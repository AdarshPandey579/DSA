#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    string text="loonbalxballpoon";
    unordered_map<char,int> freq;
    string b="balloon";
    int count=0;
    for(char ch : text){
        freq[ch]++;
    }
    while(true){
        for(char ch : b){
            if(freq.find(ch)==freq.end() || freq[ch]==0){
                cout << count;
                return 0;
            }
            freq[ch]--;
        }
        count++;
    }
    cout << count;
    return 0;
}