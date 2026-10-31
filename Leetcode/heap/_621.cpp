#include <bits/stdc++.h>
using namespace std;


int main(){
    string tasks = "AAABBB";
    int n = 2;
    unordered_map<char,int> freq,next;
    for(char ch : tasks) freq[ch]++;
    priority_queue <pair<int,char>> pq;
    for(auto item : freq){
        pair<int,char> p;
        p.first=item.second;
        p.second=item.first;
        pq.push(p);
        next[item.first] = 1;
    }
    int seats=1;
    while(!pq.empty()){
        vector<pair<int,char>> side;
        while(!pq.empty()){
            pair<int,char> p = pq.top();
            pq.pop();
            int freq = p.first;
            char ch = p.second;
            if(next[ch]<=seats){
                if(freq>1) pq.push({freq-1,ch});
                next[ch] = seats + n + 1;
                break;
            }
            else{
                side.push_back(p);
            }
        }
        for(int i=0; i<side.size(); i++) pq.push(side[i]);
        seats++;
    }
    cout << --seats << endl;
    return 0;
}