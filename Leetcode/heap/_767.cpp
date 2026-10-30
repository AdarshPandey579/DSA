#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

struct cmp{
    bool operator()(pair<int,char>& a, pair<int,char>& b){
        if(a.first!=b.first) return a.first < b.first;
        return a.second > b.second;
    }
};

int main(){
    string s = "aab";
    priority_queue<pair<int,char>,vector<pair<int,char>>,cmp> pq;

    unordered_map<char,int> freq;
    for(char ch : s) freq[ch]++;

    for(auto item:freq){
        pair <int,char> p;
        p.first=item.second;
        p.second=item.first;
        pq.push(p);
    }

    string ans="";
    while(!pq.empty()){
        pair<int,char> p1=pq.top();
        pq.pop();
        if(ans.empty() || ans.back()!=p1.second){
            ans+=p1.second;
            if(p1.first>1) pq.push({p1.first-1,p1.second});
        }
        else{
            pair<int,char> p2=pq.top();
            pq.pop();
            ans+=p2.second;
            if(p2.first>1) pq.push({p2.first-1,p2.second});
            pq.push(p1);
        }
        
    }
    cout << ans << endl;
    return 0;
}