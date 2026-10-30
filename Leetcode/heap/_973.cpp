#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct cmp{
    bool operator()(pair<int,int>& a, pair<int,int>& b){
        if(a.second!=b.second) return a.second < b.second;
        return a.first > b.first;
    }
};

int main(){
    vector<vector<int>> points={{3,3},{5,-1},{-2,4}};
    int k=2;
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    int n=points.size();
    for(int i=0; i<n; i++){
        pair <int,int> p;
        p.first=i;
        p.second= points[i][0]*points[i][0] + points[i][1]*points[i][1];
        pq.push(p);
        if(pq.size()>k){
            pq.pop();
        }
    }
    vector<vector<int>> ans(k);
    for(int i=k-1;i>=0;i--){
        ans[i]=points[pq.top().first];
        pq.pop();
    }
    
    for(vector<int> vec : ans){
        cout<<'['<<" ";
        for(int num : vec) cout<<num<<" ";
        cout<<"] ";
    }
    return 0;
}