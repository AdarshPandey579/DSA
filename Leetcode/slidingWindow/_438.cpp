#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



int main(){
    string s = "cbaebabacd";
    string p = "abc";
    int n = s.size();
    int m = p.size();
    unordered_map<char, int> freq;
    for(char ch : p) freq[ch]++;

    vector<int> ans;
    
    unordered_map<char, int> temp;
    for(int j = 0; j < m; j++) temp[s[j]]++;
    if(temp == freq) ans.push_back(0);

    for(int i = m; i < n; i++) {
        temp[s[i]]++; // add incoming character
        temp[s[i-m]]--; // remove outgoing character
        if(temp[s[i-m]]==0) temp.erase(s[i-m]);
        if(temp == freq) ans.push_back(i-m+1);
    }
    for(int a : ans) cout << a << ' ';
    return 0;
}