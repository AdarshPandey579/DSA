#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

struct cmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }
};

int main(){
    vector<int> nums = {2, 3, 1, 3, 2};
    unordered_map<int, int> mp;
    for(int num : nums) mp[num]++;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for(auto item : mp){
        int frq = item.second;
        int num = item.first;
        pq.push({frq,num});
    }
    vector<int> ans;
    while(!pq.empty()){
        int frq = pq.top().first;
        int num = pq.top().second;
        for(int i=0; i<frq; i++){
            ans.push_back(num);
        }
        pq.pop();
    }
    for(int a : ans) cout << a << ' ';
    return 0;
}