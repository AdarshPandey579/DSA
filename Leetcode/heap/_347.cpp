#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

struct cmp{
    bool operator()(pair<int,int>& a, pair<int,int>& b){
        if(a.second!=b.second) return a.second > b.second;
        return a.first < b.first;
    }
};

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    unordered_map <int,int> freq;
    for(int num : nums) freq[num]++;

    for(auto item : freq){
        pq.push(item);
        if(pq.size()>k){
            pq.pop();
        }
    }
    vector<int> ans(k);
    for(int i=k-1;i>=0;i--){
        ans[i]=pq.top().first;
        pq.pop();
    }
    for(int num : ans) cout<<num<<" ";
    return 0;
}