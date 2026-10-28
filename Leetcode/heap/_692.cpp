#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<unordered_map>
using namespace std;

struct cmp{
    bool operator() (pair<int,string>& a, pair<int,string>& b){
        if(a.first!=b.first) return a.first>b.first; // numerically smaller at top
        return a.second<b.second; // alphabetically larger at top
    }
};

int main(){
    vector<string> words={"i","love","leetcode","i","love","coding"};
    int k=2;
    priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
    unordered_map <string,int> freq;
    for(string word : words) freq[word]++;

    for(auto item : freq){
        pair<int , string> p;
        p.first=item.second;
        p.second=item.first;
        pq.push(p);
        if(pq.size()>k){
            pq.pop();
        }
    }

    vector<string> ans(k);
    for(int i=k-1;i>=0;i--){
        ans[i]=pq.top().second; // numerically smaller and alphabetically larger at end.
        pq.pop();
    }
    
    for(string word : ans) cout<<word<<" ";
    return 0;
}